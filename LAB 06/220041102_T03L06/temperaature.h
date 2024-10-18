#ifndef temperaature_H
#define temperaature_H

class temprature{
    private:
        float temp;
    public:
        temprature();
        temprature(float);
        void display();
        temprature operator+(temprature);
        temprature operator-(temprature);
}

#endif // temperaature_H
