using static System.Console;

public class Program {
  public static void Main(string[] args) {
    var manager = new Manager(1, "AAAAA", 55, 10);
    var developer = new Developer(2, "JJJJ", 100, 2, 3);

    WriteLine("manager: " + manager.GetEmployeeInfo());
    WriteLine("developer: " + developer.GetEmployeeInfo());
  }
}
