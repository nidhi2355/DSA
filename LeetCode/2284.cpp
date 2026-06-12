/*
2284. Sender With Largest Word Count

You have a chat log of n messages. You are given two string arrays messages and senders where messages[i] is a message sent by senders[i].
A message is list of words that are separated by a single space with no leading or trailing spaces. The word count of a sender is the total number of words sent by the sender. Note that a sender may send more than one message.

Return the sender with the largest word count. If there is more than one sender with the largest word count, return the one with the lexicographically largest name.

Note:

Uppercase letters come before lowercase letters in lexicographical order.
"Alice" and "alice" are distinct.
*/

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> wordCnt;
        int maxCnt=0;
        string sender;
        for(int i=0;i<messages.size();i++){
            int cnt=0;
            for(int j=0;j<messages[i].size();j++){
                if(messages[i][j]==' ') cnt++;
            }
            cnt++;
            wordCnt[senders[i]]+= cnt;
            if(wordCnt[senders[i]]>maxCnt){
                maxCnt= wordCnt[senders[i]];
                sender= senders[i];
            }
            else if(wordCnt[senders[i]]==maxCnt){
                sender= max(sender, senders[i]);
            }
        }
        return sender;
    }
};
