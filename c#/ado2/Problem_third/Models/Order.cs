using System;
using System.Collections.Generic;

namespace Prob_3.Models;

public class Order {
  public int Id { get; set; }
  public string CustomerName { get; set; } = null!;
  public decimal TotalAmount { get; set; }
  public DateTime OrderDate { get; set; }

  public List<OrderItem> Items { get; set; } = new();
}
