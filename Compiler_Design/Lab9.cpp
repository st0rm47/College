#include <bits/stdc++.h>
using namespace std;

struct Production { string lhs; vector<string> rhs; };

// Tokenize input string
vector<string> tokenize(const string &s){
    vector<string> tokens;
    for(size_t i=0;i<s.size();){
        if(i+1<s.size() && s.substr(i,2)=="id"){ tokens.push_back("id"); i+=2; }
        else if(s[i]=='('||s[i]==')'||s[i]==',') { tokens.push_back(string(1,s[i])); i++; }
        else if(isspace(s[i])) i++;
        else { cerr<<"Unknown symbol: "<<s[i]<<endl; exit(1);}
    }
    return tokens;
}

// Check if top of stack matches RHS
bool match_top(const vector<string>& stack,const vector<string>& rhs){
    if(stack.size()<rhs.size()) return false;
    for(size_t i=0;i<rhs.size();i++)
        if(stack[stack.size()-rhs.size()+i]!=rhs[i]) return false;
    return true;
}

// Reduce as much as possible
bool try_reduce(vector<string>& stack, const vector<Production>& G, const vector<string>& tokens, size_t index){
    // Try longest RHS first
    for(auto &p:G){
        if(match_top(stack,p.rhs)){
            for(size_t i=0;i<p.rhs.size();i++) stack.pop_back();
            stack.push_back(p.lhs);

            stringstream ss;
            ss<<left<<setw(20); for(auto &s:stack) ss<<s<<" ";
            ss<<" | "<<setw(15); for(size_t j=index;j<tokens.size();j++) ss<<tokens[j];
            ss<<" | Reduce: "<<p.lhs<<" ->"; for(auto &x:p.rhs) ss<<" "<<x;
            cout<<ss.str()<<"\n";

            return true;
        }
    }
    return false;
}

int main(){
    int n; cout<<"Enter number of productions: ";
    cin>>n; cin.ignore();

    vector<Production> G;
    cout<<"Enter productions (e.g. S->S+S):\n";
    for(int i=0;i<n;i++){
        string line; getline(cin,line);
        size_t arrow=line.find("->");
        string lhs=line.substr(0,arrow);
        string rhs=line.substr(arrow+2);
        vector<string> rhs_tokens;
        for(size_t j=0;j<rhs.size();){
            if(j+1<rhs.size() && rhs.substr(j,2)=="id"){ rhs_tokens.push_back("id"); j+=2; }
            else if(rhs[j]=='('||rhs[j]==')'||rhs[j]==','||isalpha(rhs[j])){ rhs_tokens.push_back(string(1,rhs[j])); j++; }
            else j++;
        }
        G.push_back({lhs,rhs_tokens});
    }

    cout<<"Enter input string: ";
    string input; getline(cin,input);
    vector<string> tokens=tokenize(input);

    vector<string> stack; size_t index=0;

    cout<<left<<setw(20)<<"Stack"<<" | "<<setw(15)<<"Input"<<" | Action\n";
    cout<<string(60,'-')<<"\n";

    while(true){
        // Keep reducing until no more possible
        bool reduced;
        do{
            reduced = try_reduce(stack,G,tokens,index);
        }while(reduced);

        // Shift next token if possible
        if(index<tokens.size()){
            stack.push_back(tokens[index]);
            stringstream ss;
            ss<<left<<setw(20); for(auto &s:stack) ss<<s<<" ";
            ss<<" | "<<setw(15); for(size_t j=index+1;j<tokens.size();j++) ss<<tokens[j];
            ss<<" | Shift: "<<tokens[index];
            cout<<ss.str()<<"\n";
            index++;
        } else break;
    }

    // Final check
    if(stack.size()==1 && stack[0]==G[0].lhs) cout<<"Accepted!\n";
    else cout<<"Rejected!\n";

    return 0;
}
