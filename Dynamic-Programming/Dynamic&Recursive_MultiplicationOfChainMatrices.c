 //															ANALUSH KAI SXEDIASH ALGORITHMWN - EXAM #4
//													        	POLLAPLASIASMOS ALUSIDWTWN PINAKWN

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 6

//	GLOBAL
int C[N][N];
int P[N][N];
int c[N][N];
int p[N][N];

//	SYNARTHSEIS
int find_k(int d[], int, int);//	RECURSION
int duna_find_k(int d[],  int);// DUNAMIKOS

    int main() {
    	int d[N] = {2, 7, 5, 4, 3, 4};// DIASTASEIS 5 PINAKWN
    	//int r[6] = {2, 7, 5, 3, 4, 3};
    	//int d[N];
    	int i, j, k;
        /*for(i = 0; i < N; i++) {
        	for(j = 0; j < N; j++) {
        		d[i] = r[rand()%6];
			}
		}*/
  		clock_t t;
   		
//=========================================  DYNAMIC WAY  ========================================	
        t = clock();
		duna_find_k(d, N);
		t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
		printf("\n\n================\n");
		printf("\nH SEIRA TWN PRAKSEWN      :");
		for(i = 0; i < N; i++) {
			k = P[i];
			printf("A[%d] * ", i+1);
			for(j = 0; j < N; j++) {
				if(k == P[j])
				   printf("(");
			}
		}
		printf("\nTO MIKROTERO KOSTOS EINAI : %d", C[1][N-1]);
		printf("\nME BHMA K                 : %d", P[1][N-1]);
	    printf("\n\nDynamic_Rec...Pinakwn() took %f seconds to execute \n\n", time_taken);
	    
//=========================================  RECURSION WAY  ========================================

//      KLHSH RECURSION 
/*        t = clock();
		find_k(d, 1, N-1);
		t = clock() - t;
	    double time_taken = ((double)t)/CLOCKS_PER_SEC;
		 
//     	PROVOLH PINAKWN
		printf("\n	PINAKAS KOSTOUS\t\t\t\t\t\tPINAKAS THESHS K\n");
		for(i = 1; i < N-1; i++) {
			printf("\n");
			for(j = 0; j < N-1; j++) 
				printf("%d\t", c[i][j]);
			printf("\t\t");
			for(j = 0; j < N-1; j++) 
				printf("%d\t", p[i][j]);
		}
		printf("\n\n================\n");
		printf("\nTO MIKROTERO KOSTOS EINAI : %d", c[1][N-2]);
		printf("\nME BHMA K                 : %d", p[1][N-2]);
		printf("\n\nDynamic_Rec...Pinakwn() took %f seconds to execute \n\n", time_taken);
*/	
	    return 0;
	}
        


int find_k(int d[], int i, int j) {
	int k,  min = 100000;
	
	if(i >= j)
	   return 0;
	   
    for(k = i; k < j; k++) {// APO 1 EWS J - 1.. ETSI ORIZOUME THN SUNARTHSH OTAN THN KALOUME
        c[i][k] = find_k(d, i, k) + find_k(d, k + 1, j) + d[i-1] * d[k] * d[j];
        p[i][k] = k;
        if(min > c[i][k]) 
           min = c[i][k];
        }
	return min;
 }

int duna_find_k(int d[], int n) { // TO "n" STHN OUSIA EINAI TO "j"
	int i, j, k, l, m;// DEIKTES
	int max = 1, min;
	
//	EUVRESH MEGALUTEROU GINOMENOU
   /* for(i = 0; i < n - 1; i++)	 
    	for(j = 1 + i; j < n; j++) 
    		max *= d[j-1]; */
    max  = 10000;
    min = max;//	 ISWS KAI OXI KALOS TROPOS... SE MEGALO PINAKA d[n] TO "int MAX" THA PAREI ARNHTIKH TIMH.
    
//	ARXIKOPOIHSH PINAKWN
    for(i = 0; i < N; i++) 
    	for(j = 0; j < N; j++) {
	        C[i][j] = 0;
		    P[i][j] = 0;
		}
     
    m = 1;/* O "m" EINAI VOHTHITIKOS DEIKTHS KAI THA PREPEI NA PERIORIZEI THN 2h FOR STIS EPANALHPSEIS... 
            Px STOUS 5 PINAKES 
				4 EPANALHPSEIS : A1*A2, A2*A3...A4*A5 
				3 EPANALHPSEIS : A1*A2*A3, A2*A3*A4, A3*A4*A5
						... KAI PAEI LEGONTAS
*/
    l = 0;/* O "l" EINAI VOHTHITIKOS DEIKTHS KAI THA PREPEI NA AUKSANEI TIS EPANALHPSEIS STHN 3h FOR... 
             PANW EKSIGISAME TI KANEI O "m". SUNEPWS DIMIOURGEITE PROVLIMA KAI OSO MEIWNETE O "m" MEIWNETAI KAI O "k" 
             ARA AUTO POU KANOUME EINAI : OSO MEIWNETE TO ORIO STHN 2h FOR, AUKSANETAI TO ORIO STHN 3h FOR 
    */
    
    for(j = 2; j < N; j++) {// j = 2 DIOTI GIA TON UPOLOGISMO 2 PINAKWN KAI PARAPANW THELOUME 3 DIASTASEIS ==> d[0] * d[1] * d[2], 2, 5, 7.
//    	printf("\n============  j = %d  ============\n\n", j);
    	l = 0;// SE KATHE ALLAGH TOU J, MIDENIZOUME TO "l" KAI KSEKINAME ENAN NEO KUKLO EPANALHPSEWN
 	    for(i = 1; i < N - m; i++) {// TO EKSIGISAME KAI PANW... OI 5 PINAKES XWRIZONTAI SE 4 ZEUGARIA PINAKWN. O 1o -> 2o, 2o -> 3o..., TA 4 ZEUGARIA SE 3 WSPOU NA FTASOUME SE 1 ZEUGARI.
// 									   TA 4 ZEUGARIA SE 3 WSPOU NA FTASOUME SE 1 ZEUGARI. OSA TA ZEUGARIA TOSES KAI OI EPANLHPSEIS TU "i"
            min = max;
    		for(k = i; k < j + l; k++) {// TO K < J, TO J EINAI ISO ME n = 6. OSO AUKSANETE TO "i" AUKSANETAI KAI TO "l". AN TO "i" AUKSHTHEI MIA FORA TOTE PREPEI NA 
//										   AUKSHTHEI KAI TO "l" EPEIDH MEGALWNEI TO BHMA... THA MPOROUSA NA TO KANW KAI DIAFORETIKA ANTI GIA "j+l" NA KANW "j+i-1"
//										   TO AFHNW ME TO "l" MHPWS EINAI PIO KATANOHTO
//			   printf("C[%d][%d] = C[%d][%d] + C[%d][%d] + d[%d] * d[%d] * d[%d] = %d\n" ,i, j+l, i, k, k+1, j+l, i-1, k, j+l, C[i][k] + C[k+1][j+l] + d[i-1]*d[k]*d[j+l]);
			    if(min > C[i][k] + C[k+1][j+l] + d[i-1]*d[k]*d[j+l]) {
			    	min = C[i][k] + C[k+1][j+l] + d[i-1]*d[k]*d[j+l];
	    	        C[i][j+l] = min;
	    	        P[i][j+l] = k;
	    	    }
			}
			l++;
		}
		m++;
	}
	//	PROVOLH PINAKWN
	printf("\n	PINAKAS KOSTOUS\t\t\t\t\t\t\tPINAKAS THESHS K\n");
        for(i = 1; i < N-1; i++) {
        	printf("\n");
        	for(j = 1; j < N; j++) 
        		printf("%d\t", C[i][j]);
			printf("\t\t\t");
			for(j = 1; j < N; j++) 
        		printf("%d\t", P[i][j]);
	    }
		return 0;
	}
 

