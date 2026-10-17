
#include <iostream>
#include <vector>
#include <atomic>
#include <thread>
#include "NKThreading/NkThreadingApi.h"
#include "NKWindow/NKMain.h"
#include "NKThreading/NkThreadPool.h"
#include "NKLogger/Sinks/NkAsyncSink.h"

using namespace nkentseu;
std::atomic<long long> g_sink{0};

// Classe conteneur pour correspondre au format de méthode de classe attendu par NkFunction
class TaskExecutor {
public:
    void RunTaskShort() {
        long long sum = 0;
        for (int j = 0; j < 1000; ++j) {
            sum += j;
        }
        g_sink.fetch_add(sum, std::memory_order_relaxed);
    }

    void RunTaskLong() {
        long long sum = 0;
        for (int j = 0; j < 100000; ++j) {
            sum += j;
        }
        g_sink.fetch_add(sum, std::memory_order_relaxed);
    }
};

// Mesure avec la réserve de threads (NkThreadPool) - Tâche courte
double MeasurePoolShort(nkentseu::threading::NkThreadPool& pool, TaskExecutor& executor) {
    nkentseu::NkChrono chrono;
    chrono.BeginPreciseTiming();
    
    for (int i = 0; i < 200; ++i) {
        // Passage de l'objet et de la méthode membre à la tâche du kit
        pool.Enqueue(nkentseu::threading::Task(&executor, &TaskExecutor::RunTaskShort));
    }
    pool.Join();
    
    return chrono.Elapsed().milliseconds;
}

// Mesure avec des threads créés manuellement - Tâche courte
double MeasureThreadsShort(TaskExecutor& executor) {
    nkentseu::NkChrono chrono;
    chrono.BeginPreciseTiming();
    
    std::vector<std::thread> threads;
    threads.reserve(200);
    
    for (int i = 0; i < 200; ++i) {
        threads.emplace_back([&executor]() { executor.RunTaskShort(); });
    }
    for (auto& t : threads) {
        t.join();
    }
    
    return chrono.Elapsed().milliseconds;
}

// Mesure avec la réserve de threads - Tâche longue
double MeasurePoolLong(nkentseu::threading::NkThreadPool& pool, TaskExecutor& executor) {
    nkentseu::NkChrono chrono;
    chrono.BeginPreciseTiming();
    
    for (int i = 0; i < 200; ++i) {
        pool.Enqueue(nkentseu::threading::Task(&executor, &TaskExecutor::RunTaskLong));
    }
    pool.Join();
    
    return chrono.Elapsed().milliseconds;
}

// Mesure avec des threads créés manuellement - Tâche longue
double MeasureThreadsLong(TaskExecutor& executor) {
    nkentseu::NkChrono chrono;
    chrono.BeginPreciseTiming();
    
    std::vector<std::thread> threads;
    threads.reserve(200);
    
    for (int i = 0; i < 200; ++i) {
        threads.emplace_back([&executor]() { executor.RunTaskLong(); });
    }
    for (auto& t : threads) {
        t.join();
    }
    
    return chrono.Elapsed().milliseconds;
}

int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::threading::NkThreadPool pool;
    TaskExecutor executor;
    
    std::cout << "Nombre d'ouvriers : " << pool.GetNumWorkers() << std::endl;

    // Échauffement (Warmup)
    MeasurePoolShort(pool, executor);
    MeasureThreadsShort(executor);

    // Mesures courtes (moyenne sur 3 exécutions)
    double t_pool_short = 0, t_threads_short = 0;
    for (int i = 0; i < 3; ++i) {
        t_pool_short += MeasurePoolShort(pool, executor);
        t_threads_short += MeasureThreadsShort(executor);
    }
    t_pool_short /= 3.0;
    t_threads_short /= 3.0;

    // Mesures longues (moyenne sur 3 exécutions)
    double t_pool_long = 0, t_threads_long = 0;
    for (int i = 0; i < 3; ++i) {
        t_pool_long += MeasurePoolLong(pool, executor);
        t_threads_long += MeasureThreadsLong(executor);
    }
    t_pool_long /= 3.0;
    t_threads_long /= 3.0;

    // Affichage des résultats pour remplir reserve.txt
    std::cout << "\n= RESULTATS " << std::endl;
    std::cout << "Tache : courte" << std::endl;
    std::cout << "Reserve : " << t_pool_short << " ms" << std::endl;
    std::cout << "Fils : " << t_threads_short << " ms" << std::endl;
    std::cout << "Ouvriers : " << pool.GetNumWorkers() << std::endl;
    std::cout << "Tache longue : long" << std::endl;
    std::cout << "Reserve : " << t_pool_long << " ms, Fils : " << t_threads_long << " ms" << std::endl;

    return 0;
}
