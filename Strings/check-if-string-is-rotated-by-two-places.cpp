class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    void rotateclockwise(string &s1)
    {
        char c=s1[s1.size()-1];
        int index=s1.size()-2;
        while(index>=0)
        {
            s1[index+1]=s1[index];
            index--;
        }
        s1[0]=c;
    }
    
    void rotateanticlockwise(string &s2)
    {
        char c=s2[0];
        int index=1;
        while(index<s2.size())
        {
            s2[index-1]=s2[index];
            index++;
        }
        s2[s2.size()-1]=c;
    }
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.size()!=str2.size()) return 0;
        string clockwise,anticlockwise;
        clockwise=str1;
        rotateclockwise(clockwise);
        rotateclockwise(clockwise);
        
        if(clockwise==str2) return 1;
        
        anticlockwise=str1;
        rotateanticlockwise(anticlockwise);
        rotateanticlockwise(anticlockwise);
        
        if(anticlockwise==str2) return 1;
        
        return 0;
       
    }

};
