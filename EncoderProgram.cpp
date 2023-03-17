#include<iostream>
#include<string>
using namespace std;

//general decliration for repeatition and encoded string
  int repeation = 1;
  string encoded = "";	


//function for duplicates
string Duplicates(string decoded, int i){
	if (repeation == 9)             		//if duplicated more than 9 times
		{
			encoded += to_string(repeation);	//add # of repeatition to output
			encoded += decoded[i];			//add character to output
			decoded[i] = NULL;	   			//removing pointer from character	
			repeation = 0;	
		}
			repeation++;
			return decoded;

}
//function for noneduplicates
int NoneDuplicates(string decoded,int i)
{
	encoded += to_string(1);
					//add 1 to output			
		while(decoded[i] != decoded[i+1])	//while there aren't duplicates
		{
			encoded += decoded[i];
						               //add character to output
			   if (decoded[i]=='1')
			   {				//if the character is 1 we add 1 to output
				  encoded += '1';				  
			   }			
			  i++;
		}			
	encoded += to_string(1);			//add 1 to output
		repeation++; //avoiding of miss one repeation
		return i; //updating the index
}
//conditions function
string RLE(string decoded)
{

  for(int i = 0; i < decoded.length(); i++) 
  {//5a1234
  	
	  	if(decoded[i] == decoded[i+1])			//to check if we have duplicates
	  	{
		  decoded=Duplicates(decoded,i);		
		}
		else if(decoded[i] != decoded[i-1] && decoded[i] != decoded[i+1] && decoded[i] != '1')  //to check if we do not have dulpicates
		{		
	  	 i = NoneDuplicates(decoded,i);
		}
		else
		{		
			encoded += to_string(repeation);	//add # of repeatition to output
			encoded += decoded[i];				//add character to output
			repeation = 1;			    	
		}	
  }		
	return encoded;
  }
int main()
{

    string decoded;
    cout<<"Enter the string to encoded: ";
    getline(cin, decoded);
 
 		//output
 	cout <<"Encoded string is: "<< RLE(decoded);	
}
