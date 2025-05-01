#include <iostream>
#include "MyNameSpace.h"
/*
int main(){
    using namespace MyNameSpace;
    cout << MyNameSpace::value << endl;
    cout << value << endl;
    using MyNameSpace::value;
    cout << value << endl;
}
*/
/*
int main(){
    using namespace MyNameSpace;
    cout << MyNameSpace::ChildNameSpace::value2 << endl;
    cout << ChildNameSpace::value2 << endl;
    using MyNameSpace::ChildNameSpace::value2;
    cout << value << endl;
    return 0;
}
*/
int main(){
    using namespace MyNameSpace;
    cout << MyNameSpace::ChildNameSpace::value2 << endl;
    cout << MyNameSpace::value << endl;
    return 0;
}