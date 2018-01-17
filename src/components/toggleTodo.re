module Mutation = Apollo.Client.Mutation;

module ToggleTodo = [%graphql{|
    mutation toggleTodo($id: ID!){
        toggleTodo(id: $id) {
            id
            title
            active
        }
    }
|}];

let component = ReasonReact.statelessComponent("ToggleTodo");

let make = (~todo, _children) => {
    ...component,
    render: (_) => 
    <Mutation>
        (
            (mutate, result) => {
                let toggleTodo = ToggleTodo.make(~id=todo##id, ());
                let parseResult = toggleTodo##parse;
                let active = switch result {
                    | Loaded(res) => parseResult(res)##toggleTodo##active
                    | _ => todo##active   
                };
                <input 
                    className="toggle" 
                    _type="checkbox" 
                    checked=active
                    onChange=((_) => mutate(toggleTodo))
                />
            }
        )
    </Mutation>
};