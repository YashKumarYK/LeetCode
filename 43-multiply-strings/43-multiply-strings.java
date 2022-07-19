class Solution {
    public String multiply(String num1, String num2) {
        if(num1.equals("0") || num2.equals("0")){
            return "0";
        }
        int n=num1.length();
        int m=num2.length();
        char[] arr1=num1.toCharArray();
        char[] arr2=num2.toCharArray();
        char[] ans=new char[n+m];
        Arrays.fill(ans,(char)(0+'0'));
        int k=n+m;
        int p=n+m;
        int carry=0;
        int mul=0;
        for(int i=m-1;i>=0;i--){
            int down =arr2[i]-'0';
            p--;
            k=p;
            carry=0;
            for(int j=n-1;j>=0;j--){
                int up=arr1[j]-'0';
                mul=(up*down)+carry+(ans[k]-'0');
                carry=mul/10;
                ans[k]=(char)(mul%10+'0');
                k--;
            }
            if(carry!=0){
                ans[k]=(char)(carry+'0');
            }
        }
        int pt=0;
        while(ans[pt]=='0'){
           pt++;
        }
        return String.valueOf(ans).substring(pt);
    }
}