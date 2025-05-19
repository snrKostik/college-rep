using static System.Console;

namespace A {

public class CareTaker {
  private List<IMemento> _mementos = new List<IMemento>();
  private Originator _originator;

  public CareTaker(Originator originator) { this._originator = originator; }

  public void Backup() {
    WriteLine("\nCareTaker: Saving some things...");
    this._mementos.Add(this._originator.Save());
  }

  public void Undo() {
    if (this._mementos.Count == 0) {
      return;
    }

    var memento = this._mementos.Last;
    this._mementos.Remove(memento);

    WriteLine("CareTaker")
  }
}

}
