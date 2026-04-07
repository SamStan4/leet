#include <vector>
#include <string>
#include <array>
#include <stdexcept>

class Robot {
private:

    static constexpr std::array<std::array<int, 2>, 4> directions = {{
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    }};

    static constexpr std::array<const char*, 4> direction_to_compass_direction = {{
        "East",
        "North",
        "West",
        "South"
    }};


    const int m_plane_width;
    const int m_plane_height;

    const int m_perimeter;

    int m_x { 0 };
    int m_y { 0 };

    int m_direction { 0 };

    int get_pending_walking_distance(const int _num) {
        switch (this->m_direction) {
            case 0:
                return std::min(_num, this->m_plane_width - this->m_x - 1);
            break;
            case 1:
                return std::min(_num, this->m_plane_height - this->m_y - 1);
            break;
            case 2:
                return std::min(_num, this->m_x);
            break;
            case 3:
                return std::min(_num, this->m_y);
            break;
        }
        throw std::runtime_error("invalid direction state");
    }

public:

    Robot(const int _width, const int _height) 
        : m_plane_width(_width), m_plane_height(_height), m_perimeter((_width * 2) + (_height * 2) - 4) {
    }
    
    void step(int _num) {
        if (_num == 0) {
            return;
        }
        _num %= this->m_perimeter;
        if (this->m_x == 0 && this->m_y == 0 && _num == 0) {
            this->m_direction = 3;
        }
        while (_num > 0) {
            const int pending_walking_distance = this->get_pending_walking_distance(_num);
            if (pending_walking_distance == 0) {
                this->m_direction = (this->m_direction + 1) % 4;
                continue;
            }
            this->m_x += pending_walking_distance * Robot::directions[this->m_direction][0];
            this->m_y += pending_walking_distance * Robot::directions[this->m_direction][1];
            _num -= pending_walking_distance;
            if (_num > 0) {
                this->m_direction = (this->m_direction + 1) % 4;
            }
        }
    }
    
    std::vector<int> getPos() const {
        return {this->m_x, this->m_y};
    }
    
    std::string getDir() const {
        return Robot::direction_to_compass_direction[this->m_direction];
    }
};