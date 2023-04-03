#include <string>
#include <iostream>
#define SIDES 2

using namespace std;

int calculate_base_length(int pyramid_levels)
{
    int pyramid_height = pyramid_levels + 2;
    int baseline_number = ((pyramid_height  + 1) * pyramid_height) / 2 - 3; //  3 + 4 + 5 + 6 (first level + second level + third level + fourth level heights) (start from 3 and above so we -2 -1)

    int base_stars_number = baseline_number * 2 - 1; // count if it was all normal triangle then add whats added between lvls up till that line
    int to_add = 2;
    for (int i = 0; i < pyramid_levels - 1; i++)
    {
        if(i % 2 == 0)
            to_add += 2;
        base_stars_number += to_add;
    }
    return (base_stars_number);
}

void print_character(char c, int count)
{
    for (int  i = 0; i < count; i++)
        cout << c;
}

void print_pyramid(int mid, int level, int &starsNum)
{
   
    int half_stars = starsNum / 2;
    const int slash = 1;
    int count_spaces = mid - half_stars - slash;
    for (int i = 0; i < 3 + level; i++)
    {
        print_character(' ', count_spaces);
        cout << "/";
        print_character('*', starsNum);
        starsNum += 2;
        cout << "\\";
        count_spaces--;
        cout << endl;
    }
}

void print_door(int nbr_door, int level)
{

    if (nbr_door > 4 && level == nbr_door / 2 + 1)
    {
        print_character('|', nbr_door - 2);
        cout << "$|";
    }
    else
        print_character('|',nbr_door);
    
}

void print_last_pyramid(int mid, int level , int &starsNum)
{
    int half_stars = starsNum / 2;
    const int slash = 1;
    int count_spaces = mid - half_stars - slash;
    int nbr_door = level + 1;
    if (nbr_door % 2 == 0)
        nbr_door--;
    int height = 3 + level;
    int j = 0;
     for (int i = 0; i < height; i++)
    {
        print_character(' ', count_spaces);
        cout << "/";
        
        if (i  >= height - nbr_door)
        {
            j++;
            int halfStarsNumDoorExcluded = (starsNum - nbr_door) / 2;
            print_character('*', halfStarsNumDoorExcluded);
            print_door(nbr_door, j);
            print_character('*', halfStarsNumDoorExcluded);
        }
        else
            print_character('*', starsNum);
        starsNum += 2;
        cout << "\\";
        count_spaces--;
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    int num;
    try{
        num = stoi(argv[1]);
    }
    catch (std::exception &e)
    {
        return 0;
    };
    if(num <= 0)
    return 0;
    int base_length = calculate_base_length(num);
    int mid_star_pos = (base_length + SIDES) / 2;
    int toAdd = 2;
    int starsNum = 1;
    for (int i = 0; i < num - 1; i++)
    {
        print_pyramid(mid_star_pos, i, starsNum);
        if (i % 2 == 0)
            toAdd += 2;
        starsNum += toAdd;
    }
    print_last_pyramid(mid_star_pos, num - 1, starsNum);

    return (0);
}
