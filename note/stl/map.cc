




To use a unordered_map You just have to design a hash function for your key. 
C++ standard library provide a set of hash function for in-built key types like: hash<int> or hash<float>. 
If you decleare a unordered_map<int,int> it'll by default use hash<int> as it's hash function. 
But if you want to use your own object as key, you have to provide your own hash function.






