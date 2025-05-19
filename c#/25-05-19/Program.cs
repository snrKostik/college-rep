using static System.Console;

// {
//     string GetDir() { return Directory.GetCurrentDirectory(); }
//
//     void AddToCurDir(string dirName)
//     {
//         DirectoryInfo dirInfo = new($"{GetDir()}/{dirName}/");
//         dirInfo.Create();
//
//         WriteLine($"Директеория успешно добавлена\n{GetDir()}/{dirName}");
//     }
//
//     void AddFile(string dirName, string fileName)
//     {
//         FileInfo fileInfo = new($"{GetDir()}/{dirName}/{fileName}");
//         fileInfo.Create();
//     }
//
//     DirectoryInfo dirInfo =
//         new DirectoryInfo($"{Directory.GetCurrentDirectory()}");
//
//     WriteLine("Выберите имя папки для создания: ");
//     string? dirName = ReadLine();
//     AddToCurDir(dirName);
//
//     WriteLine("Введите имя файла: ");
//     string? fileName = ReadLine();
//     AddFile(dirName, fileName);
// }

var employees = new List<Employee> {
  new Employee { Id = 1, Name = "Иванов", Department = "IT",
                 Position = "Программист", Salary = 120000 },
  new Employee { Id = 2, Name = "Смирнов", Department = "IT",
                 Position = "Программист", Salary = 110000 },
  new Employee { Id = 3, Name = "Белова", Department = "IT",
                 Position = "Тестировщик", Salary = 90000 },
  new Employee { Id = 4, Name = "Орлова", Department = "HR",
                 Position = "Менеджер", Salary = 75000 },
  new Employee { Id = 5, Name = "Кузнецов", Department = "HR",
                 Position = "Рекрутер", Salary = 70000 },
  new Employee { Id = 6, Name = "Петрова", Department = "Finance",
                 Position = "Бухгалтер", Salary = 80000 },
  new Employee { Id = 7, Name = "Федоров", Department = "Finance",
                 Position = "Аналитик", Salary = 95000 },
  new Employee { Id = 8, Name = "Сидоров", Department = "IT",
                 Position = "Админ", Salary = 85000 },
  new Employee { Id = 9, Name = "Морозова", Department = "IT",
                 Position = "Тестировщик", Salary = 91000 },
  new Employee { Id = 10, Name = "Григорьев", Department = "Finance",
                 Position = "Аналитик", Salary = 97000 },
  new Employee { Id = 11, Name = "Лебедев", Department = "HR",
                 Position = "Менеджер", Salary = 78000 },
  new Employee { Id = 12, Name = "Егорова", Department = "Finance",
                 Position = "Бухгалтер", Salary = 82000 },
  new Employee { Id = 13, Name = "Александров", Department = "IT",
                 Position = "Программист", Salary = 115000 },
  new Employee { Id = 14, Name = "Николаева", Department = "HR",
                 Position = "Рекрутер", Salary = 72000 },
  new Employee { Id = 15, Name = "Зайцев", Department = "IT",
                 Position = "Админ", Salary = 88000 },
  new Employee { Id = 16, Name = "Дмитриева", Department = "Sales",
                 Position = "Менеджер по продажам", Salary = 88000 },
  new Employee { Id = 17, Name = "Михайлов", Department = "Sales",
                 Position = "Менеджер по продажам", Salary = 89000 },
  new Employee { Id = 18, Name = "Волкова", Department = "Sales",
                 Position = "Аналитик", Salary = 94000 },
  new Employee { Id = 19, Name = "Соколова", Department = "Finance",
                 Position = "Аналитик", Salary = 99000 },
  new Employee { Id = 20, Name = "Баранов", Department = "Finance",
                 Position = "Бухгалтер", Salary = 78000 },
  new Employee { Id = 21, Name = "Попов", Department = "IT",
                 Position = "Программист", Salary = 125000 },
  new Employee { Id = 22, Name = "Анисимова", Department = "HR",
                 Position = "Менеджер", Salary = 79000 },
  new Employee { Id = 23, Name = "Ковалёв", Department = "Finance",
                 Position = "Аналитик", Salary = 96000 },
  new Employee { Id = 24, Name = "Тарасов", Department = "Sales",
                 Position = "Аналитик", Salary = 93000 },
  new Employee { Id = 25, Name = "Виноградова", Department = "Sales",
                 Position = "Менеджер по продажам", Salary = 90000 }
};

var deps =
    from employee in employees
    group employee by employee.Department into dep
    select new
    {
        Department = dep.Key,
        // Count = dep.Count(),
        Names = from employee in dep select employee,
        Positions = from empl in dep
                    group empl by empl.Position into emp
                    select new { emp.Key, Names = from name in emp select name}
                    // avgSal = from empl in dep.Average()
    };

// var names = from employee in deps
//             group employee by employee.Name into n
//             select new { Name = n.Key };

foreach (var empl in deps)
{
    WriteLine($"DEP: {empl.Department} ");
    WriteLine($"  Pos: {empl.Positions}");

    // WriteLine($"\tNames:");
    //
    // foreach (var names in empl.Names)
    // {
    //     WriteLine($"\t\t{names.Name}");
    // }
}

class Employee
{
    public int Id { get; set; }
    public string Name { get; set; }
    public string Department { get; set; }
    public string Position { get; set; }
    public decimal Salary { get; set; }
}
