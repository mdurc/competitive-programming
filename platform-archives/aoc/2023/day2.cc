#include <bits/stdc++.h>

// input should start at the first number of the first group of balls
// part 1
bool new_game(std::ifstream& in){
    std::string temp;

    int r,g,b;
    r=g=b=0;

    bool valid_game = true;
    int save;
    while(in >> temp){

        // check if we just finished the game
        if(temp[0] == 'G'){ break; }

        // convert the number of balls
        save = std::stoi(temp);

        // take in the color
        in >> temp;
        char& c = temp[0];

        if(c=='r'){ r+=save; }
        else if(c=='g'){ g+=save; }
        else{ b+=save; }


        // done with one group of the current game.
        // Either end of first group or end of game
        if(temp.back() == ';' || temp.back()!=','){
            if(valid_game) valid_game = r<=12 && g<=13 && b<=14;
            r=g=b=0; 
        }
    }
    return valid_game;
}


// part 2
int new_game_two(std::ifstream& in){
    std::string temp;

    int minr=0, ming=0, minb=0;
    int r=0,g=0,b=0;

    while(in >> temp){

        // check if we just finished the game
        if(temp[0] == 'G'){ break; }

        // convert the number of balls
        int save = std::stoi(temp);

        // take in the color
        in >> temp;
        char& c = temp[0];

        if(c=='r'){ r+=save; }
        else if(c=='g'){ g+=save; }
        else{ b+=save; }


        // done with one group of the current game.
        // Either end of first group or end of game
        if(temp.back() == ';' || temp.back()!=','){
            minr = std::max(minr, r);
            ming = std::max(ming, g);
            minb = std::max(minb, b);
            r=g=b=0; 
        }
    }
    return minr*ming*minb;
}

int main(){

    std::ifstream in_one("in.txt");
    std::ifstream in_two("in.txt");

    if (!in_one.is_open() || !in_two.is_open()){
        std::cerr << "error open: input.txt";
        return 1;
    }
    
    int sum_one = 0;
    int sum_two = 0;
    
    std::string temp;
    in_one >> temp;
    in_two >> temp;

    while(in_one >> temp){
        if(new_game(in_one)){
            sum_one+=std::stoi(temp);
        }

        in_two >> temp;
        sum_two += new_game_two(in_two);
    }
    std::cout << "part a: " << sum_one << std::endl;
    std::cout << "part b: " << sum_two << std::endl;


    return 0;
}
