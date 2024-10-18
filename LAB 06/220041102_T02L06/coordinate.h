#ifndef C1D75225_85F4_46A5_B5D0_CD3EF907205A
#define C1D75225_85F4_46A5_B5D0_CD3EF907205A

class coordinate{
    private:
        float x,y;
    public:
        coordinate() : x(0), y(0) {}
        coordinate(float a, float b) : x(a), y(b) {}
        ~coordinate(){}

        void display();

        float operator - (coordinate &c);

        float getDistance();
        void move_x(float val);
        void move_y(float val);
        void move(float x_val, float y_val);

        bool operator>(const coordinate &c);
        bool operator<(const coordinate &c);
        bool operator==(const coordinate &c);
        bool operator!=(const coordinate &c);
        bool operator>=(const coordinate &c);
        bool operator<=(const coordinate &c);
};

#endif /* C1D75225_85F4_46A5_B5D0_CD3EF907205A */
