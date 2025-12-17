using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.EntityFrameworkCore;

namespace MyApp;

public class Book {
  public int BookId { get; set; }
  public string Title { get; set; } = string.Empty;
  public int AuthorId { get; set; }

  public Author? Author { get; set; }
}
