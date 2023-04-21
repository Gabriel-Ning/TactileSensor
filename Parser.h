#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <sstream>
#include <vector>
#include <QDebug>

///
/// \brief The Tactile information struct
struct TactileStates
{
    TactileStates()
    {
        impedence_.fill(0);
    }

    std::array<int,16> impedence_;

    void fromMessage(char* recv)
    {
        std::string receive_string{recv};


        if(receive_string.front() = '#')
        {
            std::vector<std::string> strings;
            std::istringstream f(receive_string.substr(1,receive_string.size()-2));
            std::string s;
            while (getline(f, s, ','))
            {
                strings.push_back(s);
            }

            if(strings.size()  == 16)
            {
                for (std::size_t i {}; i < strings.size(); i++)
                {
                    impedence_[i] = std::stoi(strings.at(i));
                }
            }
        }
        else
        {
            // Do Nothing
        }
    }

    void makeComparison(const TactileStates& anotherState,std::vector<bool>& contactStates)
    {



    }

    void setState(const TactileStates& ts)
    {
        for(std::size_t i {}; i < this->impedence_.size(); i++)
        {
            this->impedence_[i] = ts.impedence_[i];
        }
    }
};





#endif // PARSER_H
