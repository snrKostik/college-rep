class Manager : Employee {
  public int Bonus { get; set; }

  public Manager(int id, string name, int salary, int bonus)
      : base(id, name, salary) {
    Bonus = bonus;
  }

  public override int CalculateSalary() { return Salary + Bonus; }

  public override string GetEmployeeInfo() {
    return base.GetEmployeeInfo() + $", bonus: {Bonus}, new salary: {Salary}";
  }
}
