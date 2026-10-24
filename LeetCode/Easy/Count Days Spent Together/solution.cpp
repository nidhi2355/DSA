class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        if(arriveBob< arriveAlice) return countDaysTogether(arriveBob, leaveBob, arriveAlice, leaveAlice);

        int arrivealice= cntDay(arriveAlice);
        int leavealice= cntDay(leaveAlice);
        int arrivebob = cntDay(arriveBob);
        int leavebob= cntDay(leaveBob);

        int start= max(arrivealice, arrivebob);
        int end= min(leavealice, leavebob);

        int days= max(0, end-start+1);
        return days;
    }

    int cntDay(string & arriveAlice){
        vector<int> dx= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int month= stoi(arriveAlice.substr(0, 2));
        int arrivealice= 0;
        if(month > 1){
            for(int i=0; i<= month-2; i++) arrivealice+= dx[i];
        } 

        int date= stoi(arriveAlice.substr(3, 2));
        arrivealice+= date;

        return arrivealice;
    }
};