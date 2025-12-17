class Developer : Employee {
  public int Overtime { get; set; }
  public int Rate { get; set; }

  public Developer(int id, string name, int salary, int overtime, int rate)
      : base(id, name, salary) {
    Overtime = overtime;
    Rate = rate;
  }

  public override int CalculateSalary() { return Salary + (Overtime * Rate); }

  public override string GetEmployeeInfo() {
    return base.GetEmployeeInfo() +
           $", overtime: {Overtime}, rate: {Rate}, new salary: {CalculateSalary()}";
  }
}
