package ClientServer_OneWay;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Client_Class {
    Socket socket;
    DataInputStream input;
    DataOutputStream output;

    public Client_Class(String ipAddress, int port) {
        // Connect to server
        try {
            socket = new Socket(ipAddress, port);
            System.out.println("Connected to server...");

            output = new DataOutputStream(socket.getOutputStream());
        } catch (IOException u) {
            u.printStackTrace();
        }

        transferType();
    }

    private void transferType() {
        try {
            System.out.print("---\n\nSend / Receive / Close Connection : ");

            Scanner scan = new Scanner(System.in);
            String type = scan.nextLine();
            output.writeUTF(type);

            switch (type.toLowerCase()) {
                case "send" ->  clientToServer();
                case "receive" -> {
                    serverToClient();
                }
                case "close connection" -> closeConnect();
                default -> transferType();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void clientToServer() {
        // SEND
        Scanner scan = new Scanner(System.in);
        String message = "";
        System.out.println("Send message to server..");

        // Read input from console
        try {
            while (!message.toLowerCase().equals("over")) {
                message = scan.nextLine();
                output.writeUTF(message);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        transferType();
    }

    private void serverToClient() {
        // RECEIVE
        String message = "";
        System.out.println("Receiving message from server...");

        try {
            input = new DataInputStream(socket.getInputStream());
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

    private void closeConnect() {
        // CLOSE CONNECTION
        try {
            if (socket != null) {
                socket.close();
            }
            if (input != null) {
                input.close();
            }
            if (output != null) {
                output.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Client_Class("127.0.0.1", 7173);
    }
}
