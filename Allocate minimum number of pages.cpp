
You are given N number of books. Every ith book has Pi number of pages. 
You have to allocate books to k number of students. 



#define ll long long int
using namespace std;
// checking whether the current number of books alloted to each student are sufficient or not
bool isValid(ll arr[],ll n,ll mid,ll k)
{
    ll sum=0,students=1;
    for(ll i=0;i<n;i++)
    {
        sum=sum+arr[i];
        if(sum>mid)
        // if sum is greater than mid then increase the total number of students
        {
            students++;
            sum=arr[i];
        }
        if(students>k) return false;
    }
    return true;
}
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
        ll n;
        cin>>n;
        ll arr[n];
        ll maxp=-1,sump=0;
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
            maxp=max(maxp,arr[i]);
            sump=sump+arr[i];
        }
        ll k;
        cin>>k;
        ll l=maxp,r=sump,res=-1;
        if(n<k) cout<<-1<<endl;
        else
        {
           
           while(l<=r)
        {
            ll mid=l+(r-l)/2;
            // if the current division is valid, then go and search for the same in left
            if(isValid(arr,n,mid,k)==true)
            {
                res=mid;
                r=mid-1;
                
            }
            // if invalid, then go to left ( means each student can have more books than the given value)
            else l=mid+1;
        }
        cout<<res<<endl;
         
        }
        
       
     }
     
	//code
	return 0;
}
