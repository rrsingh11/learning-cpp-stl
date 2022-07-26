#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=5;
    int a[n]={ 3 , 4 , 7 , 2 , 1} ;
    array<int,5> b = { 2 , 3 , 6 , 5 , 4};
    //Only constant required, n cannot be used. Maybe because of this we use a[n] notation not array<int,size>

    vector<int> vec = { 9 , 5 , 8 , 3 , 1};
    
//Sorting -------------->O(nlog n)          =>[)
    //ASCENDING ORDER
    sort(a , a+n); //{1 , 2 , 3 , 4, 7}
    sort(b.begin() , b.end()); // {2 ,3 , 4 , 5 , 6}
    sort(vec.begin(),vec.end()); // { 1 , 3 , 5 , 8 , 9}

    for(int i=0;i<n;i++)
    {
        cout << a[i] << "|";
        cout << b[i] << "|";
        cout << vec[i] << "|";
        cout << endl; 
    }

    //DESCENDING ORDER
    // use greater<int>() to sort "anything" in descending order
    sort(a , a+n, greater<int>()); //{7 , 4 , 3 , 2, 1}
    sort(b.begin() , b.end(),greater<int>()); // {6 ,5 , 4 , 3 , 2}
    sort(vec.begin(),vec.end(),greater<int>()); // { 9 , 8 , 5 , 3 , 1}

    for(int i=0;i<n;i++)
    {
        cout << a[i] << "|";
        cout << b[i] << "|";
        cout << vec[i] << "|";
        cout << endl; 
    }

    //Suppose you need to sort from index 2 to 5
    vector<int> vec = {3, 4, 9, 1, 5};
    sort(vec.begin()+2 , vec.begin()+6); // [2 , 6)  => { 3 , 4 , 1 , 5 , 9}

    for(auto it:vec)
        cout << "[2,6) => " <<  it << " ";
    cout << endl;






//Reverse   => [)
    reverse(a , a+n);
    reverse(b.begin() , b.end());
    reverse(vec.begin() , vec.end());
    //Same thing like sorting for a particular range of reversing
    
    for(int i=0;i<n;i++)
    {
        cout << a[i] << "|";
        cout << b[i] << "|";
        cout << vec[i] << "|";
        cout << endl; 
    }




//Maximum / Minimum element => max_element & min_element are iterators
    int el = *max_element(a , a+n); //  lly (b.begin(),b.end()) & (vec.begin() , vec.end())
    cout << el << endl;

    int el = *min_element(a,a+n); // lly (b.begin(),b.end()) & (vec.begin() , vec.end())
    cout << el << endl;





//To find the sum of the range 
//accumulate(first-iterator , last-iterator , inital-sum  )
    int sum = accumulate(a ,a+n , 0);  // lly (b.begin(),b.end(), inital-sum ) & (vec.begin() , vec.end(), inital-sum)
    cout << sum << endl;





// To find the number of times a particular value 'x'  occured.
// count(first-iterator , last-iterator , x )
    int x = 3;
    int a[5] = {3,3,3,1,4};
    int cnt = count(a,a+5,x); //lly (b.begin(),b.end(),x) & (vec.begin() , vec.end(),x)
    cout << cnt << endl;




//To find the first occurance of  'x' 
// find(first-iterator , last-iterator , x )
    int x = 2;
    int a[5] = {1,3,2,4,2};
    auto it = find(a,a+5,x); // It return an iterator over first occurance of the number and if not present it return end()
    //lly (b.begin(),b.end(),x) & (vec.begin() , vec.end(),x)

    cout << it-a << endl; // (a-b) / distance(a,b) mostly used to get index => a=iterator b=.begin()
    //lly (it-b.begin()) & (it-vec.begin())






//Binary Search - To find whether the element is in the container or not
//binary_search(first-iterator , last-iterator , x ) -Only works on sorted arrays------------------> O(log n)
    int arr[5] = {1,2,4,7,9};
    int x = 7;
    bool flag = binary_search(arr , arr+5 , x);  //lly (b.begin(),b.end(),x) & (vec.begin() , vec.end(),x)
    //binary_search() returns true if element is in the container or false value is not present

    cout << flag << endl; //True
//Note: .find() works on all kind does not matter sorted or not but has more time complexity





// lower_bound function    ----------------------> O(log n)
// lower_bound(first-iterator , last-iterator , x ) - Only works on sorted arrays
//It returns an iterator pointing to the first element which is "not less" than x. if not present it will point to .end()
//Basically "equal to" or "just greater" than 'x' 
    int arr[10] = {1,3,5,5,5,7,8,8,10,15};
    int p = 5; 
    int q = 13;
    int r = 16;

    auto p_it  = lower_bound(arr ,arr+10,p); //Ponits to 5          =>index = 2
    auto q_it  = lower_bound(arr ,arr+10,q); //Points to 15         =>index = 9
    auto r_it  = lower_bound(arr ,arr+10,r); //Points to endl()     =>index = 10 
    //lly (b.begin(),b.end(),x) & (vec.begin() , vec.end(),x)
    //To print index
    cout << p_it - arr << endl; //2
    cout << q_it - arr << endl; //9
    cout << r_it - arr << endl; //10 





//Upper Bound function
// upper_bound(first-iterator , last-iterator , x ) - Only works on sorted arrays
//It returns an iterator pointing to the first element which is "just greater" than x. if not present it will point to .end()
//Basically "just greater" than 'x' 
    int arr[10] = {1,3,5,5,5,7,8,8,10,15};
    int p = 5; 
    int q = 13;
    int r = 15;

    auto p_it  = upper_bound(arr ,arr+10,p); //Ponits to 7          =>index = 5    
    auto q_it  = upper_bound(arr ,arr+10,q); //Points to 15         =>index = 9
    auto r_it  = upper_bound(arr ,arr+10,r); //Points to endl()     =>index = 10 
    //lly (b.begin(),b.end(),x) & (vec.begin() , vec.end(),x)
    //To print index
    cout << p_it - arr << endl; //5
    cout << q_it - arr << endl; //9
    cout << r_it - arr << endl; //10 






/*
    Suppose, string s = "abc"
    all permutations are as follows:
        -abc
        -acb
        -bac
        -bca
        -cab
        -cba
*/

// Next permutation -----------------> O(n)
//next_permutation(first-iterator , last iterator)
    string s1 ="abc";
    string s2 = "cba";

    bool ans_s1 = next_permutation(s1.begin(),s1.end()); // now, s-> acb & ans->true 
    //It will shift the string to next permutation and returns true as it get to change to next step
    cout << s1 << endl; //acb
    cout << ans_s1 << endl; // 1 (true)

    bool ans_s2 = next_permutation(s2.begin(),s2.end()); // now, s->abc & ans-> false
    //There is no new permutation after 'cba'. so it will return false as it does not get to change to new permutation
    cout << s2 << endl; //abc
    cout << ans_s2 << endl; // 0 (false)


    //To print all the permutation for a permutation 'bca'
    string str1 = "bca";
    //for all permutation convert it into 'abc'
    sort(str1.begin() , str1.end()); //str = abc

    do
    {
        cout << str1 << endl;
    } while (next_permutation(str1.begin(),str1.end()));




// Previous permutation -----------------> O(n)
//prev_permutation(first-iterator , last iterator)
    string st1 ="abc";
    string st2 = "cba";

    bool ans_st1 = prev_permutation(st1.begin(),st1.end()); // now, s-> 'cannot be change to prev permutation' & ans->flase 
    //There is no new permutation before 'abc'. so it will return false as it does not get to change to new permutation
    cout << st1 << endl;    //cba
    cout << ans_st1 << endl;//0 (false)

    bool ans_st2 = prev_permutation(st2.begin(),st2.end()); // now, s->'cab' & ans-> true
    //It will shift the string to previous permutation and returns true as it get to change to next step
    cout << st2 << endl;    //cab
    cout << ans_st2 << endl;    //1 (true)


    //To print all the permutation for a permutation 'bca'
    string str2 = "bca";
    //for all permutation convert it into 'cba'
    sort(str2.begin() , str2.end(),greater<int>()); //str = cba

    do
    {
        cout << str2 << endl;
    } while (prev_permutation(str2.begin(),str2.end()));
    


    return 0;
}





