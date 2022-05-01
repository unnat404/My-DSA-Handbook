// package My-DSA-Handbook.java.networking;

// public class server {
    
// }
import java.io.BufferedReader;
import java.io.DataOutput;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
 
public class server {
    public static void main(String args[]) throws Exception{
        final int port=8000;
        ServerSocket skt= new ServerSocket(port);
        System.out.println("UP and running on port :"+port);
        while(true)
        {
            Socket clientSocket=skt.accept();
            BufferedReader inFromClient = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
 
            String clientMessage=inFromClient.readLine();
            System.out.println("From Client : "+ clientMessage);
            String unstuffedMessage = "";
            for(int i=1;i<clientMessage.length()-1;i++){
                if(clientMessage.charAt(i)=='e')
                {
                    unstuffedMessage+=clientMessage.charAt(i+1);
                    i++;
                }
                else{
                    unstuffedMessage+=clientMessage.charAt(i+1);
                }
            }
            System.out.println("The unstuffed message is : "+ unstuffedMessage); 
        }
        
       
    }   
}