import 'package:flutter/material.dart';
import 'package:get/get.dart';

import 'logic.dart';

class HomePage extends StatelessWidget {
  final logic = Get.put(HomeLogic());

  HomePage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Socket Example with GetX"),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            ElevatedButton(
              onPressed: logic.connectToSocket,
              child: const Text('Connect to socket'),
            ),
            ElevatedButton(
              onPressed: () => logic.sendToSocket('r'),
              child: const Text('Write r to esp32'),
            ),
            ElevatedButton(
              onPressed: () => logic.sendToSocket('e'),
              child: const Text('Write e to esp32'),
            ),
            ElevatedButton(
              onPressed: logic.closeSocket,
              child: const Text('Close socket'),
            ),
          ],
        ),
      ),
    );
  }
}
