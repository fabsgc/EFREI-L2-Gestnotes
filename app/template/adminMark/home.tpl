<include src="include/header"/>

<table class="table">
	<thead>
		<tr>
			<th class="matricule">Id</th>
			<th>Nom</th>
		<tr>
	</thead>
	<tbody>
		<foreach loop="$groups as $data">
			<tr>
				<td>{$data['id']}</td>
				<td><a href="/admin/mark/group/{$data['id']}">{$data['name']}</a></td>
			</tr>
		</foreach>
	<tbody>
</table>

<include src="include/footer"/>