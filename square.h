#pragma once

class Square{
    public:
        double get_side();
        double get_area();
        void set_size(double size);
        

    private:
        double side_length;
        double area;

};