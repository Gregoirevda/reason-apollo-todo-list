let component = ReasonReact.statelessComponent("TodoItem");

let make = (~todo, _children) => {
    ...component,
    render: (_) => 
    <li className="todo">
        <div className="view">
            <ToggleTodo todo=todo/>
            <label> <String text=todo##title/> </label>
        </div>
    </li>
};