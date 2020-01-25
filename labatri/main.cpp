#include <iostream>


 void ent_mas(int len_mass, int mass[])
{

    for(int i=0; i < len_mass; i++){
        printf("mass[%d] = ", i);
        scanf("%d", &mass[i]);
    }
}


void output_mas(int len_mass, int mass[]){
    for(int m = 0; m < len_mass; m++)
    {
        printf("%d ", mass[m]);
    }
    printf("\n");
}

void pol_el(int n, int mass[]){
    for(int i = 0; i < n; i++){
        if( mass[i] > 0){
            printf("%d ", mass[i]);
        }
    }
    printf("\n");
}

void otr_el(int n, int mass[]){
   for(int i = 0; i<n; i++){
   if(mass[i] < 0){
       printf("%d ", mass[i]);
      }
   }
}


 int main() {

int n,k;

printf("Введите n: ");
scanf("%d", &n);

printf("Введите k: ");
scanf("%d", &k);


int m_n[n];
int m_k[k];

ent_mas(n,m_n);
ent_mas(k,m_k);

printf("Элементы массива:\n ");
output_mas(n,m_n);
output_mas(k,m_k);

printf("Положительные элементы:\n ");
pol_el(n,m_n);
pol_el(k,m_k);

printf("Отрицательные элементы:\n ");
otr_el(n,m_n);
otr_el(k,m_k);

int p_count = 0;
int p_mass = 0;
int n_count = 0;
int n_mass = 0;

for(int i=0; i<n; i++){
    if(m_n[i] > 0 && m_n[i]%2 == 1){
        p_mass +=m_n[i];
                p_count++;
    }
    if(m_n[i]<0 && m_n[i]%2==0){
        n_mass +=m_n[i];
        n_count++;
    }
}

     for(int i=0; i<k; i++){
         if(m_k[i] > 0 && m_k[i]%2==1){
             p_mass += m_k[i];
             p_count++;
         }
         if(m_k[i]<0 && m_k[i]%2==0){
             n_mass += m_k[i];
             n_count++;
         }
     }



     double sr_ar1;
     sr_ar1 = p_mass*1.0/p_count*1.0;

     printf("%f\n ");
     printf("%f", sr_ar1);

     double sr_ar2;
     sr_ar2 = n_mass*1.0/n_count*1.0;

     printf("%f\n ");
     printf("%f", sr_ar2);

    return 0;
}
