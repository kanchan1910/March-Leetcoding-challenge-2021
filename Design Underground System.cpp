class UndergroundSystem {
public:
    map<int , pair<string , int>>in; // {id,{statioName , time}}
    map<int , pair<string , int>>out; // {id , {stationName , time}}
    map<pair<string , string> , pair<int , int >>ans;
    // {{startlocation , endlocation}, {totaldistance,number of ids(people)}}
    UndergroundSystem()
    {
        
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        in[id] = {stationName, t};
        
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        out[id] = {stationName , t};
        pair<string , string> p = {in[id].first , out[id].first};
        if(ans.find(p) == ans.end())
        {
            ans[p] = {out[id].second - in[id].second , 1};
        }
        else
        {
            ans[p] = {ans[p].first + out[id].second - in[id].second , 1 + ans[p].second};
        }
        
    }
    
    double getAverageTime(string startStation, string endStation)
    {
        double result = 0.0;
        pair<int , int > pp = ans[{startStation , endStation}];
        result = (double)pp.first / (double)pp.second;
        return result;
        
    }
};

// Nice problem
