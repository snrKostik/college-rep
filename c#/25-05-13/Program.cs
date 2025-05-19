using static System.Console;
// using namespace A;

namespace A {
class Program {
  record class Student(string Name, string Fac, int Course);

  void Task1() {
    List<Student> students = new() {
      new("Вася", "Дизайн", 1), new("Игорь", "КБ", 2),
      new("Егор", "РПО", 3),    new("Яша", "Маркетинг", 4),
      new("Данил", "РПО", 1),   new("Ярик", "РПО", 2),
      new("Владимир", "КБ", 3), new("Катя", "Дизайн", 4),
      new("Саша", "Дизайн", 1), new("Женя", "Дизайн", 2),
    };
    var grouped = students.GroupBy(s => new { f = s.Fac, c = s.Course })
                      .OrderBy(g => g.Key.f);

    foreach (var group in grouped) {
      WriteLine($"Fac: {group.Key.f}");

      foreach (var inner in group) {
        WriteLine($"    Course:\t{group.Key.c}");
        WriteLine($"    Count:\t{group.Count()}");
        Write("    Names:\t");
        foreach (var student in group) {
          Write($"{student.Name}, ");
        }
        WriteLine("\n");
      }
    }
  }
  public static void Main() {
    // Program p = new();
    // p.Task1();
    JP a = new();
    a.Task2();
  }
}
}
/*
В университете хранится список студентов. У каждого студента есть следующие
свойства:

Имя (string)

Факультет (string)

Курс (int)

Требуется:

Создать список из не менее чем 10 студентов с разными факультетами и курсами.

Сгруппировать студентов по курсу с помощью LINQ.

Для каждой группы вывести:

Номер курса

Количество студентов на этом курсе

Имена студентов


Курс: 1
Количество студентов: 3
Имена: Иванов, Смирнова, Белова

Курс: 2
Количество студентов: 4
Имена: Петров, Сидоров, Никифоров, Орлова
...
*/
