#include <iostream>
#include <vector>

using namespace std;

vector <string> subseq_byreturn(string str){

    if(str.length()==0){
        vector <string> base;
        base.push_back("");
        return base;
    }

    char ch=str[0];

    vector <string> smallAns=subseq_byreturn(str.substr(1));
    vector <string> myAns;

    for(string s:smallAns){
      
      myAns.push_back(ch+s);
      myAns.push_back(s);
            
    }

    return myAns;
}

int subseq_byvoid(string str,string ans){

    if(str.length()==0){
        cout<<ans<<" ";
        return 1;
    }

    int count=0;

    char ch=str[0];

    count+=subseq_byvoid(str.substr(1),ans+ch);
    count+=subseq_byvoid(str.substr(1),ans);

    return count;
}

string buttons[]={"yz",":;/","abc","def","ghi","jkl","mno","pqrs","uv","wx","*#","+-/"};

vector <string> nokiaKeypad_byReturn(string str){
   
    if(str.length()==0){
        vector <string> base;
        base.push_back("");
        return base;
    }

    char ch=str[0];

    string button=buttons[ch-'0'];
    
    vector <string> smallAns=nokiaKeypad_byReturn( str.substr(1) );
    vector <string> myAns;
    
    for(int i=0;i<button.length();i++){
        
        char letterOfButton=button[i];

        for(string s:smallAns){
         myAns.push_back( letterOfButton + s );
        }
   
    } 

    return myAns;

}


//my approach
// void nokiaKeypad_byVoid2(string str, vector<string> ans){
    
//     if(str.length()==0){
//         for(string s:ans){
//             cout<<s<<" ";
//         }
      
//     }
     
//     char ch=str[0];
//     string button=buttons[ch-'0'];
    
//     int count=0;

//     for(string s:ans){
//         ans.erase( ans.begin() + count );
        
//         for(int i=0;i<button.length();i++){
//             ans.push_back(s+button[i]);
//         }
        
//         count++;
//     }

//     nokiaKeypad_byVoid2(str.substr(1),ans);

// }


int nokiaKeypad_byVoid1(string str,string ans){
     
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return 1;
    }
     
    int count=0;
   
    int first_digit=str[0]-'0';
    string button=buttons[first_digit];

    for(int i=0;i<button.length();i++){
        
        count+=nokiaKeypad_byVoid1(str.substr(1),ans+button[i]);
    }

    if(str.length()>1){
     
       int second_digit=str[1]-'0';
       int num=first_digit*10 + second_digit;

       if(num>=10 && num<=11){
           
           
            string button=buttons[num];
    
        
            for(int i=0;i<button.length();i++){
        
              count+=nokiaKeypad_byVoid1(str.substr(1),ans+button[i]);
            }
        }

        

    }



    return count;
}
void set1(){

    // vector <string> arr=subseq_byreturn("abcd");
    // for(string s:arr){
    //     cout<<s<<endl;
    // }

    // int res=subseq_byvoid("abcd","");
    // cout<<res;
     
    // vector <string> ans=nokiaKeypad_byReturn("589");
   
    // for(string s:ans){
        
    //     cout<<s<<" ";
    // }
    
    // vector <string> ans;
    // ans.push_back("");
    // nokiaKeypad_byVoid2("589",ans);
    
    int res=nokiaKeypad_byVoid1("101101","");
    cout<<res;
    
}


void solve(){

    set1();

}

int main(){
    
    solve();

}
