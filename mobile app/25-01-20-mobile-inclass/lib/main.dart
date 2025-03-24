import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class Viewportasdf extends StatelessWidget {
  const Viewportasdf({super.key});

  @override
  Widget build(BuildContext context) {
    return SingleChildScrollView(
      // Wrap the Column with SingleChildScrollView
      child: Column(children: <Widget>[DayOfWeekScreen(), SomeMiscThings()]),
    );
  }
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Viewportasdf(),
    );
  }
}

class DayOfWeekScreen extends StatefulWidget {
  const DayOfWeekScreen({super.key});

  @override
  _DayOfWeekScreenState createState() => _DayOfWeekScreenState();
}

class SomeMiscThings extends StatefulWidget {
  const SomeMiscThings({super.key});

  @override
  _SomeMiscThingsState createState() => _SomeMiscThingsState();
}

class _DayOfWeekScreenState extends State<DayOfWeekScreen> {
  String inputText = "";

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Сезоны"),
      ),
      body:
          // padding: const EdgeInsets.all(8.0),
          // child:
          Center(
              child: Column(
        children: [
          TextField(
            decoration: InputDecoration(
              labelText: "Введите номер сезона",
            ),
            onChanged: (text) {
              inputText = text;
            },
          ),
          Scaffold(
              // height: 20,
              // width: 40,
              ),
          ElevatedButton(
              onPressed: () {
                int seasonNumber = int.tryParse(inputText) ?? 0;
                String dayResult = getDayName(seasonNumber);

                ScaffoldMessenger.of(context)
                    .showSnackBar(SnackBar(content: Text(dayResult)));
              },
              child: Text("Узнать номер сезона"))
        ],
      )),

      // child: Center(
    );
  }

  String getDayName(int seasonNumber) {
    switch (seasonNumber) {
      case 1:
        return "Зима";
      case 2:
        return "Весна";
      case 3:
        return "Лето";
      case 4:
        return "Осень";
      default:
        return "Error";
    }
  }
}

class _SomeMiscThingsState extends State<SomeMiscThings> {
  String inputText2 = "";

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        // height: 20,
        // width: 40,
// child: Padding(
        // padding: EdgeInsets.all(8.0),
        // child: Column(
        body: Center(
            child: Column(
      children: [
        TextField(
          decoration: InputDecoration(
            labelText: "Введите что-нибудь",
          ),
          onChanged: (text) {
            inputText2 = text;
          },
        ),
        Scaffold(
            // height: 20,
            // width: 40,
            ),
        ElevatedButton(
            onPressed: () {
              String inputSomeThings = inputText2;
              String dayResult = getSomeThings(inputSomeThings);

              ScaffoldMessenger.of(context)
                  .showSnackBar(SnackBar(content: Text(dayResult)));
            },
            child: Text("Узнать что-то"))
      ],
    )));

    // child: Center(
    // )
  }

  String getSomeThings(String inputSomeThings) {
    switch (inputSomeThings) {
      case 'D':
        return "это Дуб";
      default:
        return "Error";
    }
  }
}
