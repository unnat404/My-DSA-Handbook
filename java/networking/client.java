import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;
 
 public class client {
    public static void main(String args[])throws Exception{
 
        Socket clientSocket = new Socket("localhost",8000);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        DataOutputStream outFromClient=new DataOutputStream(clientSocket.getOutputStream());
        System.out.println("Enter your string : ");
        String inFromClient=br.readLine();
        System.out.println("The entered string is : "+inFromClient);
        String stuffedString="f";
        for(int i=0;i<inFromClient.length();i++){
            if(inFromClient.charAt(i)=='e' || inFromClient.charAt(i)=='f')
            {
                stuffedString+='e';
                stuffedString+=inFromClient.charAt(i);
            }
            else{
                stuffedString+=inFromClient.charAt(i);
            }
        }
        stuffedString+='f';
        outFromClient.writeBytes(stuffedString+'\n');
        clientSocket.close();
    }
}