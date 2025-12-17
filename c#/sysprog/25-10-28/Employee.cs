class Employee {
  public int Id { get; set; }
  public string Name { get; set; }
  public int Salary { get; set; }

  public Employee(int id, string name, int salary) {
    Id = id;
    Name = name;
    Salary = salary;
  }

  public virtual int CalculateSalary() { return Salary; }

  public virtual string GetEmployeeInfo() {
    return $"\n\tid: {Id}, name: {Name}, salary: {Salary}";
  }
}
