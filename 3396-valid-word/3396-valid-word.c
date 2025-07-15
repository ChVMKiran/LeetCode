bool isValid(char* word) {
    if(strlen(word)<3)return false;
    int i=0,a=0,b=0;
    while(word[i]){
        if((word[i]>64&&word[i]<91)||(word[i]>96&&word[i]<123)){
            if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'||word[i]=='A'||word[i]=='E'||word[i]=='I'||word[i]=='O'||word[i]=='U')a++;
            else b++;
        }
        if(word[i]=='$'||word[i]=='#'||word[i]=='@')return false;
        i++;
    }
    if(a&&b)return true;
    return false;
}