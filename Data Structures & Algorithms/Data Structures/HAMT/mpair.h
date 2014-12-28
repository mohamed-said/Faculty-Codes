#ifndef MPAIR_H
#define MPAIR_H

template<class type1, class type2>
class mpair{
public:
    type1 first;
    type2 second;

    mpair() { return; }
    mpair(type1 f, type2 s)
    {
        first=f;
        second=s;
    }

    mpair<type1,type2> operator = (mpair<type1,type2> &other)
    {
        first=other.first;
        second=other.second;
    }
};

#endif // MPAIR_H
