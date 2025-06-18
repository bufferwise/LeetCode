class Solution {
private:
    int now;
    bool cdata(string &code)
    {
        constexpr char head[] = "[CDATA[" , end[] = "]]>";
        constexpr int head_len = 7 , end_len = 3;
        now += 2;
        for(int i = 0 ; i < head_len ; i++)
        {
            if(now + i >= code.size())return 0;
            if(code[now+i] != head[i])return 0;
        }
        now += head_len;
        for(int k = 0 ; k < end_len ; now++)
        {
            if(now >= code.size())return 0;
            if(code[now] == end[k])k++;
            else k = 0;
        }
        now--;
        return 1;
    }
    bool tag(string &code)
    {
        int start = now+1;
        // read tag name
        if(code[now++] != '<')return 0;
        for(int i = 0 ; i < 10 ; i++)
        {
            if(now + i == code.size())return 0;
            if(i && code[now+i] == '>')
            {
                now += i;
                break;
            }
            if(code[now+i] < 'A' || code[now+i] > 'Z')return 0;
            if(i == 9)return 0;
        }
        //read content
        for( ; ; now++)
        {
            if(now + 1 >= code.size())return 0;
            if(code[now] == '<')
            {
                if(code[now+1] == '/')
                {
                    now += 2;
                    for(;;now++,start++)
                    {
                        if(now >= code.size())return 0;
                        if(code[now] != code[start])return 0;
                        if(code[now] == '>')return 1;
                    }
                }
                else if(code[now+1] == '!')
                {
                    if(!cdata(code))return 0;
                }
                else if(!tag(code))return 0;
            }
        }
        return 0;
    }
public:
    bool isValid(string code) {
        now = 0;
        return tag(code) && now == code.size()-1;
    }
};
