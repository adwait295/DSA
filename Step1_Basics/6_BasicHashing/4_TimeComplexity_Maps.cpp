/*
Both storing an element and fetching an element
in maps take O(log n)
in all cases i.e. best, average and worst cases. 
(where n is the number of elements in the map)
*/

/*
We can use unordered-maps too to do the hashing.
We just have to do unordered_map<int,int> instead of 
map<int,int> and rest everything is same, in 
the lines of code as well as the output.

The only difference is the order in which the keys 
are stored. As they are unordered, so they can be stored
in any order

Hence the T.C. in best and average case becomes O(1) for
both storing and fetching
and the T.C. in worst case becomes O(n) which happens
once a blue moon.

n is the number of elements in the unordered map.

So the T.C. becomes the advantage in most cases
for unordered maps.
*/

/*
e.g. While pre-computing:
unordered_map<int,int>mpp;
for(int i=0;i<n;i++) ---------------O(n)
{
    cin >> arr[i];
    mpp[arr[i]]++; ------------------O(n)
}

and hence in the worst case the code's T.C. becomes O(n^2) while storing
which happens once in a blue moon
*/

/*
So preferably, we use unordered maps in most cases.
But when the problem statement has strict
TLE(Time Limit Exceeded) limitations, we go back to maps
*/

// The worst case happens due to internal collisions.

/*
In maps, the keys can be anything:
int, double, char, string, anything.
can even be pair<int,int>, vector , anything.
any data type can be a key in a map.

When it comes to unordered maps:
we can only have individual data types as keys.
i.e. 
pair<int,int> cannot be a key.
vector<int> cannot be a key.
int, double, char, string can be a key.
*/