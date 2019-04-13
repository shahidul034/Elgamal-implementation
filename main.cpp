/*******************
copyright 2019
MD. Shahidul Salim Shakib
Roll:1507034
CSE,KUET

*****************/

#include<iostream>
#include <stdlib.h>
#include<stdio.h>
#include <gmp.h>
#include<set>
#include <sstream>
#include <string>
#include<cmath>
#include <unistd.h>
#include <fcntl.h>
using namespace std;
void get_random_n_bits(mpz_t r, size_t bits)
{
    size_t size = (size_t) ceilf(bits/8);
    char *buffer = (char*) malloc(sizeof(char)*size);
    int prg = open("/dev/random", O_RDONLY);
    read(prg, buffer, size);
    close(prg);
    mpz_import (r, size,1,sizeof(char), 0,0, buffer);
    free(buffer);
}

mpz_t p,d,E2,generator,R,C1,C2,msg,de_msg,temp1,temp2,one,output,t1;
mpz_in()
{

    mpz_init(p);
    mpz_init(d);
    mpz_init(E2);
    mpz_init(generator);

    mpz_init(C1);
    mpz_init(C2);
    mpz_init(msg);
    mpz_init(de_msg);
    mpz_init(temp1);
    mpz_init(temp2);
    mpz_init(one);
    mpz_init(output);
    mpz_init(t1);


}
mpz_clr()
{
    mpz_clear(p);
    mpz_clear(d);
    mpz_clear(E2);
    mpz_clear(generator);

    mpz_clear(C1);
    mpz_clear(C2);
    mpz_clear(msg);
    mpz_clear(de_msg);
    mpz_clear(temp1);
    mpz_clear(temp2);
    mpz_clear(one);

    mpz_clear(output);
    mpz_clear(t1);


}

int prime_num()
{
    mpz_in();
    int PRIMESIZE;
    cout<<"Enter No of bits for P and Q: ";
    cin>>PRIMESIZE;

    char* p_str = new char[PRIMESIZE+1];

    p_str[0] = '1';

    for(int i=1; i<PRIMESIZE; i++)
    {
        p_str[i] = char((rand()%2)+48);

    }
    p_str[PRIMESIZE] = '\0';

    mpz_set_str(p,p_str,2);

    mpz_nextprime(p,p);
    printf("prime number = [%s]\n", mpz_get_str(NULL,10,p));


    /*
     long long int g=1;
    string pp=mpz_get_str(NULL,10,p);
    std::string text = pp;
    int number;
    std::istringstream iss (text);
    iss >> number;
    cout<<"prime: "<<number<<endl;
        for (g=1; g<=(number-1); g++)
        {
            set<long long int>s;
            for (int x=1; x<=(number-1); x++)
            {
                long long int k=pow(g,x);
                long long int k2=k % number;
                s.insert(k2);
            }
            if (s.size()==(number-1))
            {
                break;
            }

        }
        long long int i = g;
        char out_string2[1024];
        std::string out_string;
        std::stringstream ss;
        ss << i;
        out_string = ss.str();
        for (int j=0; j<out_string.size(); j++)
        {
            out_string2[j]=out_string[j];

        }
        out_string2[out_string.size()]='\0';
        mpz_set_ui(generator,0);
        mpz_set_str(generator,out_string2,10);
        printf("generator number = [%s]\n", mpz_get_str(NULL,10,generator));
        */
    do
    {
        get_random_n_bits(generator,mpz_sizeinbase(p,2));
        mpz_nextprime(generator,generator);
    }
    while (mpz_cmp(generator,p)>=0);

    printf("generator number = [%s]\n", mpz_get_str(NULL,10,generator));

    do
    {
        printf("Enter a private number: ");
        char dd[1024];
        cin>>dd;
        mpz_set_ui(d,0);
        mpz_set_str(d,dd,10);
    }
    while(!(mpz_cmp(d, p) < 0) );



    printf("private number = [%s]\n", mpz_get_str(NULL,10,d));
    mpz_set_ui(one,1);

    mpz_powm(E2,generator,d,p);

    do
    {
        printf("Enter a random number: ");
        char RR[1024];
        cin>>RR;
        mpz_set_str(R,RR,10);
    }
    while(!(mpz_cmp(R, p) < 0) );






    mpz_powm(C1,generator,R,p);

    do
    {
        printf ("Enter your msg: ");
        char msg2[1024];
        cin>>msg2;
        mpz_set_str(msg,msg2,10);
    }
    while(!(mpz_cmp(msg, p) < 0) );



    printf("Original Message = [%s]\n", mpz_get_str(NULL,10,msg));


    mpz_powm(temp1,E2,R,p);
    mpz_mul(temp2,msg,temp1);
    mpz_powm(C2,temp2,one,p);


    mpz_powm(C1, C1, d, p);
    mpz_invert(C1, C1, p);
    mpz_mul(de_msg, C2, C1);
    mpz_mod(de_msg, de_msg, p);
    printf("decrypt msg = [%s]\n", mpz_get_str(NULL,10,de_msg));












}

int main()
{
    prime_num();




}
