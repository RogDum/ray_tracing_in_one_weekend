#include <iostream>
#include <iomanip>
#include <random>
#include <math.h>
#define M_C 65535
#include "pic.h"

const int NX = 10000, NY = 10000;

int main()
{
    Pic m_p = Pic(NX, NY);
    m_p.pr();
    std::cout << m_p[1][1];
}