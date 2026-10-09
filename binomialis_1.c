#include <stdio.h>

int LNKO(int nagy, int kicsi)
{
    int maradek = 1, csere;

    if (nagy < kicsi)
    {
        csere = nagy;
        nagy = kicsi;
        kicsi = csere;
    }
    while (kicsi != 0)
    {
        maradek = nagy % kicsi;        
        nagy = kicsi;
        kicsi = maradek;
    }
    return nagy;
}

int main()
{
    int szam_1, szam_2, seged, j = 0, sz_2_s;
    long long unsigned eredmeny = 1;
    int num[40], den[40];

    scanf("%d%d", &szam_1, &szam_2);

    if (szam_2 > szam_1)
    {
        return 0;
    }
    
    if (szam_1 - szam_2 < szam_2)
    {
        seged = szam_2;
        szam_2 = szam_1 - szam_2;
    }
    else
    {
        seged = szam_1 - szam_2;
    }
    sz_2_s = szam_2;
    for (int i = szam_1; i > seged; i--)
    {
        num[j] = i;
        den[j] = sz_2_s;
        j++;
        sz_2_s--;
    }

    for (int i = 0; i < szam_2; i++)
    {
        for (int k = 0; k < szam_2; k++)
        {
            if (den[k] > 1)
            {
                int oszto = LNKO(num[i], den[k]);

                if (oszto > 1)
                {
                    num[i] /= oszto;
                    den[k] /= oszto;
                }
            }
        }
    }

    for (int i = 0; i < szam_2; i++)
    {
        eredmeny *= num[i];
    }
    printf("%llu", eredmeny);

    /*printf("%d %d %d\n", szam_1, szam_2, seged);
    for (int i = 0; i < szam_2; i++)
    {
        printf("%d %d\n", num[i], den[i]);
    }*/    
    return 0;
}