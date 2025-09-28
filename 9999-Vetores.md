# [Vector in C++ STL - from:](https://www.geeksforgeeks.org/cpp/vector-in-cpp-stl/)

A vector represents a dynamic sized array in the Standard Template Library(STL) that automatically grows when elements are added beyond current capacity.

A programmer does not have to worry about maintaining the capacity and allocating extra space initially.
Certain insertions and removals can become slightly costly in terms of time as it internally resizes itself beyond certain predefined limits. If time taken for these operations is super critical, then use of plain arrays in C++ should be preferred.
Vectors support bound checking by using v.at(i) for accessing an element at index i in a vector v.

# include <iostream>

# include <vector>

using namespace std;

int main() {

    // Declares an empty vector

    vector<int> v1;

    

    // Declares vector with given size

    // and fills it with a value

    vector<int> v2(3, 5);  

    

    // Print items of v2

    for (int x : v2) {

        cout << x << " ";

    }

    

    cout << endl;

    

    // Initializes vector using 

    // initializer list.

    vector<int> v3 = {1, 2, 3};  

    

    // Print items of v3

    for (int x : v3) {

        cout << x << " ";

    }

    

    return 0;

}

Output

5 5 5
1 2 3

Declaration and Initialization of a Vector

A vector is defined as the std::vector class template in the <vector> header file.

vector<T> v;

where T is the data type of elements and v is the name assigned to the vector.
Operations in Vector

Vectors in C++ support various useful operations that allow you to add, remove, access, and modify elements dynamically.
Insert Elements

    push_back(value) : Inserts element at the end of the vector efficiently.
    Takes constant time O(1) on average, so it's very fast.
    insert(position, value) : Inserts element at any position (beginning, middle, or end).
    Takes linear time O(n), as it shifts elements to make space.

# include <iostream>

# include <vector>

using namespace std;

​

int main() {

    vector<char> v = {'a', 'f', 'd'};

  

    // Inserting 'z' at the back

    v.push_back('z');

  

    // Inserting 'c' at index 1

    v.insert(v.begin() + 1, 'c');

​

    for (int i = 0; i < v.size(); i++)

        cout << v[i] << " ";

    return 0;

}

Output

a c f d z

Access elements

    You can access elements in a vector using v[i] for direct access or v.at(i) for bounds-checked access.
    Both return the element at index i, but at(i) throws an exception if i is out of range.
    It takes constant time O(1) on average, so it's very fast.

# include <iostream>

# include <vector>

using namespace std;

​

int main()

{

    vector<int> v = {10, 20, 30, 40};

    

    // Accessing using operator[]

    cout << "Element at index 2 using []: " << v[2] << endl;

    

    // Accessing using at()

    cout << "Element at index 3 using at(): " << v.at(3) << endl;

    

    // Uncommenting the next line will throw an 

    // out_of_range exception 

    // cout v.at(10)<<endl;

    return 0;

}

Output

Element at index 2 using []: 30
Element at index 3 using at(): 40

Update elements

    To update an element, you simply use its index with the assignment operator, for example v[i]=newValue;
    This replaces the old element at index i with the new value you want.

# include <iostream>

# include <vector>

using namespace std;

​

int main()

{

​

    vector<int> v = {10, 20, 30};

    cout << "Original value at index 1: " << v[1] << endl;

​

    // Updating the element at index q

    v[1] = 50;

​

    cout << "Updated value at index 1: " << v[1] << endl;

    return 0;

}

Output

Original value at index 1: 20
Updated value at index 1: 50

Find Vector Size

We can find the size(number of elements) of a vector using the size() function, like v.size().

# include <iostream>

# include <vector>

using namespace std;

​

int main() {

    vector<char> v = {'a', 'c', 'f', 'd', 'z'};

​

    // Finding size

    cout << v.size();

  

    return 0;

}

Output

5

Traverse Vector

    Traversing a vector means going through each element one by one, usually using a loop.
    You can use a for loop with an index (v[i]), a range-based for loop (for(int x: v)), or iterators.
    It takes linear time O(n) .

# include <iostream>

# include <vector>

using namespace std;

​

int main() {

    vector<char> v = {'a', 'c', 'f', 'd', 'z'};

​

    // Traversing vector using range based for loop

    for (int i = 0; i < v.size(); i++)

        cout << v[i] << " ";

    return 0;

}

Output

a c f d z

Delete Elements

    Elements can be deleted from a vector using erase(), which requires an iterator pointing to the element. It takes linear time O(n) because all elements after the erased one need to be shifted.
    To remove the last element efficiently, use pop_back() . It takes constant time O(1) on average, so it's very fast.

# include <iostream>

# include <vector>

# include <algorithm>

using namespace std;

​

int main() {

    vector<char> v = {'a', 'c', 'f', 'd', 'z'};

​

    // Deleting last element 'z'

    v.pop_back();

  

    // Deleting element 'f'

    v.erase(find(v.begin(), v.end(), 'f'));

    

    for (int i = 0; i < v.size(); i++) {

        cout << v[i] << " ";

    }

    return 0;

}

Output

a c d

Vector is Empty

    To check if the vector is empty we use empty() function. It returns true if the vector has no elements ,and false otherwise.
    This is useful before accessing or modifying the vector to avoid errors.

# include <iostream>

# include <vector>

using namespace std;

​

int main() {

​

    vector<int>v;

    

    // Check if the vector is empty

    if(v.empty()){

        cout<<"Vector is empty."<<endl;

    }

    

    // Add an element

    v.push_back(100);

    if(!v.empty()){

        cout<<"Vector is not empty. First element "<<v[0]<<endl;

    }

    return 0;

}

Output

Vector is empty.
Vector is not empty. First element 100

Multidimensional Vectors

Multidimensional vectors are dynamic arrays that can store data in more than one dimension, like tables or grids.
They are implemented using vector inside another vector, allowing flexible row-column (2D), or even higher-dimensional structures.
Declaration of a 2D Vector

vector<vector<int>> matrix;

Initialization of 2D Vector

vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// 3 rows , 4 columns all initialized to 0
vector<vector<int>>matrix(3,vector<int>(4,0));

Accessing Elements of 2D Vector

We can access elements using two indices:

// Outputs 6
cout << matrix[1][2];  

Traversing a 2D Vector

# include <iostream>

# include <vector>

using namespace std;

​

int main() {

​

    vector<vector<int>>matrix={

        {1,2,3},

        {4,5,6},

        {7,8,9}

    };

    cout<<"Traversing 2D vector using index-based loop:\n";

    

    // Traversing using index-based for loop

    for(int i=0;i<matrix.size();i++){

        for(int j=0;j<matrix[i].size();j++){

            cout<<matrix[i][j]<<" ";

        }

        cout<<endl;

    }

    return 0;

}

Output

Traversing 2D vector using index-based loop:
1 2 3
4 5 6
7 8 9

Vector in C++
Visit Course explore course icon
Explore

    C++ Basics
    Core Concepts
    OOP in C++
    Standard Template Library(STL)
    Practice & Problems

geeksforgeeks-footer-logo
Corporate & Communications Address:
A-143, 7th Floor, Sovereign Corporate Tower, Sector- 136, Noida, Uttar Pradesh (201305)
Registered Address:
K 061, Tower K, Gulshan Vivante Apartment, Sector 137, Noida, Gautam Buddh Nagar, Uttar Pradesh, 201305
GFG App on Play Store
GFG App on App Store

    Company
    About Us
    Legal
    Privacy Policy
    Contact Us
    Advertise with us
    GFG Corporate Solution
    Campus Training Program

    Explore
    POTD
    Job-A-Thon
    Community
    Blogs
    Nation Skill Up

    Tutorials
    Programming Languages
    DSA
    Web Technology
    AI, ML & Data Science
    DevOps
    CS Core Subjects
    Interview Preparation
    GATE
    Software and Tools

    Courses
    IBM Certification
    DSA and Placements
    Web Development
    Programming Languages
    DevOps & Cloud
    GATE
    Trending Technologies

    Videos
    DSA
    Python
    Java
    C++
    Web Development
    Data Science
    CS Subjects

    Preparation Corner
    Aptitude
    Puzzles
    GfG 160
    DSA 360
    System Design

@GeeksforGeeks, Sanchhaya Education Private Limited, All rights reserved
Lightbox
