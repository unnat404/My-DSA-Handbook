// public class byte_stuff__port_print {

// }
/*
1. Math calculator UDP [Week 3]
2. UDP IP port and address printing [18/5/22]
3. Byte Stuffing (TCP) [18/5/22]
*/

// ====================================================================================================
// Week 3
// Math Calculator with checking :: UDP
// Server
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/**
 *
 * @author student
 */
public class MathServer_092 {
//    boolean checkOperand(String operand){
//        if(operand == "1" || operand == "2" || operand == "3" || operand == "0")
//            return true;
//        return false;
//    }
public static void main(String argv[])throws Exception{
    int operator1,operator2,ans=0,flag;
    String operand;
//        MathServer_092 obj = new MathServer_092();

    ServerSocket skt = new ServerSocket(9999);
    System.out.println("Server is up and running...");
    Socket connectionSocket = skt.accept();
    System.out.println("Connection established to server...");
    BufferedReader inFromClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
    DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());
    while(true){
        
        outToClient.writeBytes("Enter 0: To Exit || Enter 1: To Add || Enter 2: To Divide || Enter 3: To Multiply\n");
        operand =inFromClient.readLine();
        if(operand.equals("0")) {
            connectionSocket.close();
//                break;
        }
        
//            do{
//                operand =inFromClient.readLine();                
//            }while(obj.checkOperand(operand));
//            operand =inFromClient.readLine();  

//            if(operand.equals("0")){
//                outToClient.writeBytes("Exiting Client\n");
//            }
        
        outToClient.writeBytes("Enter operator 1\n");
        operator1 = Integer.parseInt(inFromClient.readLine());
        outToClient.writeBytes("Enter operator 2\n");
        operator2 = Integer.parseInt(inFromClient.readLine());
        flag=0;
        int div_zero=0;
        switch(operand){
            case "1":
                ans = operator1+operator2;
                break;
            case "2":
                if(operator2==0){
                    div_zero=1;break;
                }
                ans = operator1-operator2;
                break;
            case "3":
                ans = operator1 * operator2;
                break;
            default:
                flag=1;
//                    outToClient.writeBytes("Enter valid operator");
        }
        if(div_zero==1) outToClient.writeBytes("Invalid Division || Div by Zero not possible \n");
        else if(flag==0) outToClient.writeBytes("Output of above caluclation is: "+String.valueOf(ans)+"\n");
        else outToClient.writeBytes("Enter valid operator\n");
    }        
}
}
//---------------------------------------------------------------------

// Client 

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/**
 *
 * @author student
 */
public class MathClient_092 {
boolean checkOperator(String operand){
    if(operand.equals("1") ||operand.equals("2") ||operand.equals("3")|| operand.equals("0"))
        return true;
    return false;
}
boolean checkOperand(String operator){
    for(int i=0;i<operator.length();i++){
        if(!Character.isDigit(operator.charAt(i))){
            return false;
        }
    }return true;
}
public static void main(String argv[]) throws Exception
{
    MathClient_092 ob = new MathClient_092();
    String operand2,operand1,operator,message;
    System.out.println("Client started...");
    Socket clientSocket=new Socket("localhost",9999);
    System.out.println("Client Connected to Server...");
    BufferedReader inFromServer=new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream()); 
//        DataInputStream inFromServerr = new DataInputStream(clientSocket.getInputStream()); 
    while(true){
        message = inFromServer.readLine();        
        System.out.println("From Server :: "+message);
        do{
            operator = br.readLine();
            System.out.println("Write valid operand choice from menu...");
        }while(!ob.checkOperator(operator));            
        outToServer.writeBytes(operator+"\n");
        if(operator.equals("0")){
                System.out.println("exiting client...");
                break;
        }
        
        message = inFromServer.readLine();        
        System.out.println("From Server :: "+message);
        do{
            operand1 = br.readLine();
            System.out.println("Write valid operator...");
        }while(!ob.checkOperand(operand1));
        outToServer.writeBytes(operand1+"\n");
        
        message = inFromServer.readLine();        
        System.out.println("From Server :: "+message);
        do{
            operand2 = br.readLine();
            System.out.println("Write valid operator...");
        }while(!ob.checkOperand(operand2));
        outToServer.writeBytes(operand2+"\n");
        
        message = inFromServer.readLine();        
        System.out.println("From Server :: "+message);
        
    }
//        System.out.println(inFromServer.readLine());
        
//        message = inFromServer.readLine();
//        System.out.println("Current Date Time:: "+sentence);
        
    clientSocket.close();
}   

}

// ====================================================================================================

// 18/5/22 Week 6
// =======================================================================================
// UDP IP Address & Port printing
    
// UDP_Server --------------------------------------------------------------------------
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
    
/*
    * To change this license header, choose License Headers in Project Properties.
    * To change this template file, choose Tools | Templates
    * and open the template in the editor.
    */
    
/**
 *
 * @author student
 */
public class UDP_Server {
    
    public static void main(String[] args) throws IOException {
            final int PORT = 8000;
            final int sizee = 1024;
            DatagramSocket ds = new DatagramSocket(8000);     
            byte[] receiveData = new byte[sizee];
            byte[] sendData = new byte[sizee];     
            BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
            System.out.println("Server Up and Running on PORT "+PORT);
            boolean running = true;
            
            while(running)
            {
                DatagramPacket receiveDP = new DatagramPacket(receiveData,receiveData.length);
                ds.receive(receiveDP);
                String clientMessage = new String(receiveDP.getData(),0,receiveDP.getLength());
                System.out.println("From Client: "+clientMessage.trim());
                if(clientMessage.toUpperCase().equals("BYE")){
                    System.out.println("Client Disconnected");
                    continue;
                }
                InetAddress ip = receiveDP.getAddress();
                System.out.println("IP Address : "+ip);
                System.out.println("Port No : "+receiveDP.getPort());
//                System.out.print("From Server : ");
                String serverMessage = "Exiting Client....";
//                String serverMessage = br.readLine();
                sendData = serverMessage.getBytes();
                DatagramPacket sendDP = new DatagramPacket(sendData, sendData.length, ip, receiveDP.getPort());
                ds.send(sendDP);
        
                receiveData = new byte[sizee];//freeing memory
            };
        
        }
}
    
// UDP_Client--------------------------------------------------------------------------
    
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
    
/*
    * To change this license header, choose License Headers in Project Properties.
    * To change this template file, choose Tools | Templates
    * and open the template in the editor.
    */
    
/**
 *
 * @author student
 */
public class UDP_Client {
    
    public static void main(String[] args) throws IOException { 
                DatagramSocket ds = new DatagramSocket();
                final int Radix = 1024;
                byte[] receiveData = new byte[Radix];
                byte[] sendData = new byte[Radix];     
                BufferedReader br = new BufferedReader( new InputStreamReader(System.in));     
                System.out.println("Client Connected , waiting for server ");
                InetAddress ip = InetAddress.getLocalHost();     
                //do
                {
                    System.out.print("Enter dummy Client Message: ");
                    String clientMessage = br.readLine();
                    sendData = clientMessage.getBytes();
                    DatagramPacket sendDP = new DatagramPacket(sendData, sendData.length, ip, 8000);
                    ds.send(sendDP);
                    
                    DatagramPacket receiveDP = new DatagramPacket(receiveData,receiveData.length);
                    ds.receive(receiveDP);
        
                    String serverMessage = new String(receiveDP.getData(),0,receiveDP.getLength());
                    System.out.println("Server Message:"+serverMessage.trim());
                    ds.close();
                }
        }
}
// =======================================================================================
    
// Byte Stuffing
// Client
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.Scanner;
    
/*
    * To change this license header, choose License Headers in Project Properties.
    * To change this template file, choose Tools | Templates
    * and open the template in the editor.
    */
    
/**
 *
 * @author student
 */ 
public class ByteStuffing_Client {
    String stuffing(String s){
        //byte stuffing
        String stuffed="F";
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            if(ch=='F' || ch=='E') stuffed=stuffed+'E'+ch;
            else stuffed+=ch;
        }
        stuffed+='F';
        return stuffed;
        
    }
    public static void main(String args[])throws IOException{
        try{
            ByteStuffing_Client ob = new ByteStuffing_Client ();
            String input, unstuffedData;
            System.out.println("Client connected...");
            Socket clientSocket = new Socket("localhost",8000);
            System.out.println("Connected to serevrrrr.....");
            DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
            BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            Scanner sc=new Scanner(System.in);
            System.out.print("Enter data to be sent:");
            input = sc.nextLine();
            String send = ob.stuffing(input);
            System.out.println("Sending Stuffed Data: "+send);
    //        input+="\n";
            outToServer.writeBytes(send+"\n");
//            unstuffedData = inFromServer.readLine();
//            System.out.println("Unstuffed Data from server :: "+unstuffedData);
//            clientSocket.close();
        }
        catch(Exception e){}        
    }
}
    
//----------------------------------------------------
// Server
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
    
/*
    * To change this license header, choose License Headers in Project Properties.
    * To change this template file, choose Tools | Templates
    * and open the template in the editor.
    */
    
/**
 *
 * @author student
 */
public class ByteStuffing_Server {
    String unstuffing(String s){
        String unstuffed="";
//        for(int i=1;i<s.length()-1;i++)
//        return "dd";
        s=s.substring(1, s.length()-1);//remove first and last F
        s=s.replaceAll("EE", "E");
        s=s.replaceAll("EF", "F");
//        for(int i=1;i<s.length()-1;i++){
//            if(s.charAt(i)=='E'){
//                if(s.charAt(i+1)=='E') unstuffed=unstuffed+"E";
//                i++;                
//            }
//            else {
//                unstuffed=unstuffed+s.charAt(i);
////                System.out.print(unstuffed+" ");
//            }
//        }
        return s;        
    }
    public static void main(String args[])throws IOException{
    
        try{
            ByteStuffing_Server ob = new ByteStuffing_Server();
            String clientInput,unstuffedData;
            
            while(true){
                ServerSocket skt = new ServerSocket(8000);
                System.out.println("Server is up and running ...");
                Socket connectionSocket = skt.accept();
                System.out.println("connected to client....");
                BufferedReader inFromClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
                DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());
                clientInput = inFromClient.readLine();
                System.out.println("Received Stuffed Data : "+clientInput);
                unstuffedData = ob.unstuffing(clientInput);
                unstuffedData +="\n";
                System.out.println("Un-Stuffed Data : "+unstuffedData);
//                outToClient.writeBytes(unstuffedData);
            }
        }
        catch(Exception e){}
    
        
    }
}
    
// =======================================================================================
    
    
    
    
    
    