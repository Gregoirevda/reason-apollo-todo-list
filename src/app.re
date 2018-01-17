let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: (_self) =>
  <section className="todoapp">
    <Header/>
    <Todos/>
  </section>
};
