// // Before formatting

// #include<vector>
// #include<iostream>
// class MyClass{
// public:
// MyClass():count(0){}
// void    AddValue(   int x){
// values.push_back(x);
// count++;}
// int GetValue (int index){
// if(index<0||index>=values.size()){return -1;}
// return values[ index];}
// private:
// std::vector<int>values;
// int     count;
// };
// int main(){MyClass m;
// m.AddValue(10);m.AddValue(20);
// std::cout<<"Value at 1 = "<<m.GetValue(1)<<"\n";return 0;}

// After formatting (Press Ctrl + S to format, rules written in settings.json for
// autoformatting on save)
#include <iostream>
#include <vector>
class my_Class
{
  public:
    my_Class() : count(0) {}
    void AddValue(int x)
    {
        values.push_back(x);
        count++;
    }
    int GetValue(int index)
    {
        if (index < 0 || index >= values.size())
        {
            return -1;
        }
        return values[index];
    }

  private:
    std::vector<int> values;
    int count;
};
int main()
{
    my_Class m;
    m.AddValue(10);
    m.AddValue(20);
    std::cout << "Value at 1 = " << m.GetValue(1) << "\n";
    return 0;
}
