package ClientServer_OneWay;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Server_Class {
    private Socket socket;
    private DataInputStream input;
    private DataOutputStream output;

    Server_Class(int port) {
        try {
            // Initialise Server
            ServerSocket server = new ServerSocket(port);
            System.out.println("Starting Server...");
            System.out.println("Server is online\n");
            System.out.println("Waiting for Client to connect...");

            // Connect to incoming socket
            socket = server.accept();
            System.out.println("Client connected over : " + port);

            input = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
            output = new DataOutputStream(socket.getOutputStream());

            // Get transfer type
            transferType();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void transferType(){
        System.out.println("\n\nWaiting for client request...");
        try {
            String type = input.readUTF();
            System.out.println(type + " request from client");
            switch (type.toLowerCase()) {
                case "send" -> clientToServer();
                case "receive" -> serverToClient();
                case "close connection" -> closeConnect();
                default -> transferType();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void clientToServer() throws IOException {
        // Receive from client
        String message = "";
        System.out.println("\nDisplaying client message---");
        try {
            while (true) {
                message = input.readUTF();
                if (message.toLowerCase().equals("over"))
                    break;
                System.out.println(message);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        transferType();
    }

    private void serverToClient(){
        // Send to client
        String message = "";
        Scanner scan = new Scanner(System.in);

        System.out.println("Send message to client..");

        try {
            while(!message.toLowerCase().equals("over")){
                message = scan.nextLine();
                output.writeUTF(message);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        transferType();
    }

    private void closeConnect() {
        // Close connection to socket
        try {
            System.out.println("Connection ended with client.");
            socket.close();
            input.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Server_Class(7173);
    }
}
