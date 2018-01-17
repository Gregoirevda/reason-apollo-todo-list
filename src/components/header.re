let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {
    ...component,
    render: (_) => 
    <header className="header">
        <h1> <String text="todos"/> </h1>
    </header>
};