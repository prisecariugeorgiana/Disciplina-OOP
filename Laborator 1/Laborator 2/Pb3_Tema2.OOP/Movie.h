#pragma once

class Movie
{
private:
    char name[256];
    int year;
    double score;
    int length;

public:
    Movie();

    void set_name(const char* n);
    const char* get_name() const;

    void set_year(int y);
    int get_year() const;

    void set_score(double s);
    double get_score() const;

    void set_length(int l);
    int get_length() const;

    int get_passed_years() const;
};
