#include <iostream>
#include <algorithm>

using namespace std;

struct Result
{
    long long vx;
    long long vy;
    long long vw;
    long long vh;
    long long mw;
    long long mh;
};

long long arrondi(long long a, long long b)
{
    return (2 * a + b) / (2 * b);
}

Result followWindow(long long W, long long H)
{
    return {0, 0, W, H, W, H};
}

Result stretch(long long RW, long long RH, long long W, long long H)
{
    return {0, 0, W, H, RW, RH};
}

Result fitLetterbox(long long RW, long long RH,long long W, long long H)
{
    Result r;

    if (W * RH <= H * RW)
    {
        r.vw = W;
        r.vh = arrondi(RH * W, RW);
    }
    else
    {
        r.vh = H;
        r.vw = arrondi(RW * H, RH);
    }

    r.vx = (W - r.vw) / 2;
    r.vy = (H - r.vh) / 2;

    r.mw = RW;
    r.mh = RH;

    return r;
}

Result integerScale(long long RW, long long RH,long long W, long long H)
{
    if (W >= RW && H >= RH)
    {
        long long k = min(W / RW, H / RH);

        if (k >= 1)
        {
            Result r;

            r.vw = RW * k;
            r.vh = RH * k;

            r.vx = (W - r.vw) / 2;
            r.vy = (H - r.vh) / 2;

            r.mw = RW;
            r.mh = RH;

            return r;
        }
    }

    return fitLetterbox(RW, RH, W, H);
}

Result fitCrop(long long RW, long long RH,long long W, long long H)
{
    Result r;

    r.vx = 0;
    r.vy = 0;
    r.vw = W;
    r.vh = H;

    if (W * RH > H * RW)
    {
        r.mw = RW;
        r.mh = arrondi(RW * H, W);
    }
    else
    {
        r.mw = arrondi(RH * W, H);
        r.mh = RH;
    }

    return r;
}

Result manual(long long AW, long long AH)
{
    return {0, 0, AW, AH, AW, AH};
}

void afficher(const char* nom, const Result& r)
{
    cout << nom << " " << r.vx << " " << r.vy << " " << r.vw << " " << r.vh << " " << r.mw << " "<< r.mh << '\n';
}

int main()
{
    long long RW, RH;
    long long AW, AH;
    long long W, H;

    cin >> RW >> RH >> AW >> AH >> W >> H;

    bool reference = (RW != 0 && RH != 0);

    Result rFollow;
    Result rStretch;
    Result rLetterbox;
    Result rInteger;
    Result rCrop;
    Result rManual;

    if (!reference)
    {
        rFollow = followWindow(W, H);

        rStretch = rFollow;
        rLetterbox = rFollow;
        rInteger = rFollow;
        rCrop = rFollow;
    }
    else
    {
        rFollow = followWindow(W, H);
        rStretch = stretch(RW, RH, W, H);
        rLetterbox = fitLetterbox(RW, RH, W, H);
        rInteger = integerScale(RW, RH, W, H);
        rCrop = fitCrop(RW, RH, W, H);
    }

    rManual = manual(AW, AH);

    afficher("FOLLOW_WINDOW", rFollow);
    afficher("STRETCH", rStretch);
    afficher("FIT_LETTERBOX", rLetterbox);
    afficher("INTEGER_SCALE", rInteger);
    afficher("FIT_CROP", rCrop);
    afficher("MANUAL", rManual);

    int bandes = 0;

    if (rFollow.vw < W || rFollow.vh < H)
        bandes++;

    if (rStretch.vw < W || rStretch.vh < H)
        bandes++;

    if (rLetterbox.vw < W || rLetterbox.vh < H)
        bandes++;

    if (rInteger.vw < W || rInteger.vh < H)
        bandes++;

    if (rCrop.vw < W || rCrop.vh < H)
        bandes++;

    if (rManual.vw < W || rManual.vh < H)
        bandes++;

    cout << "BANDES " << bandes << '\n';

    bool deformation =
        reference &&
        (W * RH != H * RW);

    if (deformation)
        cout << "DEFORMATION OUI\n";
    else
        cout << "DEFORMATION NON\n";

    return 0;
}