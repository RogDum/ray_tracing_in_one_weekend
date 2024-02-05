#pragma once
#include <fstream>
#include <vector>
#include "vec3.h"
#include <cstdlib>

#ifndef M_C
#define M_C 255
#endif // !M_C
typedef Vec3 Pix;

std::ofstream outfile;

int RandInt(int min, int max) {
    std::random_device seed;//硬件生成随机数种子
    std::ranlux48 engine(seed());//利用种子生成随机数引擎
    std::uniform_int<> distrib(0, M_C);//设置随机数范围，并为均匀分布
    int random = distrib(engine);//随机数
    return random;
}

class Pic {
public:
    struct Lin {
        std::vector<Pix> n;
        inline Pix& operator[](int i) { return n[i]; }
        inline Pix  operator[](int i) const { return n[i]; }
        void pr() {
            for (auto a : n) {
                outfile << a << "\n";
            }
            outfile << "\n";
        }
    };
    Pic() {}
    Pic(int x, int y) {
        for (size_t i = 0; i < y; i++)
        {
            Lin p_l;
            for (size_t j = 0; j < x; j++)
            {
                Pix t_px;
                t_px[1] = RandInt(0, M_C) % int(double(i) / double(x) * M_C + 1);
                t_px[0] = RandInt(0, M_C) % int(double(j) / double(y) * M_C + 1);
                t_px[2] = RandInt(0, M_C);
                p_l.n.push_back(t_px);
            }
            n.push_back(p_l);
        }
    }
    std::vector<Lin> n;
    inline Lin& operator[](int i) { return n[i]; }
    inline Lin  operator[](int i) const { return n[i]; }
    void pr() {
        outfile.open("out.ppm");
        outfile << "P3\n";
        outfile << n[0].n.size() << " " << n.size() << "\n";
        outfile << M_C << "\n";
        for (auto a : n) a.pr();
    }
};