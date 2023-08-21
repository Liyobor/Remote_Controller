import 'dart:io';

import 'package:flutter/foundation.dart';
import 'package:get/get.dart';

class HomeLogic extends GetxController {
  Socket? socket;

  Future<void> connectToSocket() async {

    try {
      socket = await Socket.connect('192.168.25.223', 8080,timeout: const Duration(seconds: 10)).then((value) {
        if (kDebugMode) {
          print("Connection successful!");
        }
        return value;
      }); // Replace ESP32_IP_ADDRESS with your ESP32's IP and PORT_NUMBER with your ESP32's port number

      // Listen for responses from the server
      socket?.listen((data) {
        if (kDebugMode) {
          print(String.fromCharCodes(data));
        }
      });

    } catch (e) {
      if (kDebugMode) {
        print("Unable to connect: $e");
      }
    }
  }



  void sendToSocket(String message){

    try {
      // Send data to ESP32
      if(socket==null){
        if (kDebugMode) {
          print("socket == null");
        }
      }
      socket?.write(message);
    } catch (e) {
      if (kDebugMode) {
        print("Unable to send: $e");
      }
    }
  }

  void closeSocket(){
    try {
      // Send data to ESP32
      socket?.close();
    } catch (e) {
      if (kDebugMode) {
        print("Unable to close socket: $e");
      }
    }
  }

}
