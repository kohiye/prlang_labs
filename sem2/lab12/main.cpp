#include <string>
#include <string_view>
#include <iostream>
#include <cmath>
#include <functional>

class BaseCharacter
{
protected:
    int m_pos_x{};
    int m_pos_y{};
    int m_hp{};
public:
    BaseCharacter(int x, int y, int hp):m_pos_x{x}, m_pos_y{y}, m_hp{hp}{};
    void move(int delta_x, int delta_y){
        m_pos_x += delta_x;
        m_pos_y += delta_y;
    };
    bool is_alive() const {return m_hp>0;};
    void damageBy(int damage){ m_hp -= damage;};

    int get_x() const {return m_pos_x;};
    int get_y() const {return m_pos_y;};

    friend int distance(const BaseCharacter& ch1, const BaseCharacter& ch2){
        int dx{ch2.m_pos_x - ch1.m_pos_x};
        int dy{ch2.m_pos_y - ch1.m_pos_y};
        return static_cast<int>(std::sqrt(dx*dx + dy*dy));
    };
};

class Weapon
{
private:
    std::string m_name{};
    int m_damage{};
    int m_range{};
public:
    Weapon() = default;
    Weapon(const std::string_view name, int damage=0, int range=0):
        m_name{name}, m_damage{damage}, m_range{range}{};

    friend std::ostream& operator<<(std::ostream& out, const Weapon& weapon){
        return (out << weapon.m_name);
    };
    friend std::istream& operator>>(std::istream& in, Weapon& weapon){
        in >> weapon.m_name;
        in >> weapon.m_damage;
        in >> weapon.m_range;
        return in;
    };
    void hit(const BaseCharacter& actor, BaseCharacter& target) const {
        if(!target.is_alive()){
            std::cout << "target is already dead.\n";
            return;
        }
        if(distance(actor, target) <= m_range){
            std::cout << "target is unreachable.\n";
            return;
        }
        target.damageBy(m_damage);
        std::cout << "target damaged with " << m_name << " by " << m_damage << '\n';
    };
};

class BaseEnemy : public BaseCharacter
{
private:
    const Weapon& m_weapon;
public:
    BaseEnemy(int x, int y, int hp, const Weapon& weapon):
        BaseCharacter{x, y, hp},m_weapon{weapon}{};
    void hit(BaseCharacter& target) const {m_weapon.hit(*this, target);};
    friend std::ostream& operator<<(std::ostream& out, const BaseEnemy& enemy){
        out << "Enemy at (" << enemy.get_x() << ", " << enemy.get_y() << ") ";
        out << "with weapon " << enemy.m_weapon;
        return out;
    };
};

class MainHero : public BaseCharacter
{
private:
    std::vector<std::reference_wrapper<Weapon>> m_inventory{};
    size_t m_selectWeaponId{};
    std::string m_name{};
public:
    MainHero(int x, int y, const std::string& name, int hp):
        BaseCharacter{x, y, hp},m_name{name}{};
    void add_weapon(Weapon& weapon){
        if(!m_inventory.size())
            m_selectWeaponId = 0;
        m_inventory.push_back(std::ref(weapon));
    };
    void next_weapon(){
        if(!m_inventory.size()){
            std::cout << "no weapons\n";
            return;
        }
        if(m_inventory.size()==1){
            std::cout << "only one weapon\n";
            return;
        }
        if (++m_selectWeaponId >= (m_inventory.size()))
            m_selectWeaponId = 0;
        std::cout << "Weapon changed to " << m_inventory[m_selectWeaponId].get() << '\n';
    };
    void heal(int amount){m_hp+=amount;};
    void hit(BaseCharacter& target) const{
        if(!m_inventory.size()){
            std::cout << "no weapons\n";
            return;
        }
        m_inventory[m_selectWeaponId].get().hit(*this, target);
    };
    
};

int main(){
    return 0;
};